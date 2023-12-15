#include "stdio.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N_WRITER 2 //写者数目
#define N_READER 4 //读者数目
#define W_SLEEP 1 //控制写时间间隔
#define R_SLEEP  1 //控制读时间间隔
 
pthread_t wid[N_WRITER],rid[N_READER];
const int MAX_RAND = 100;//产生的最大随机数
int data = 0;
int readerCnt = 0, writerCnt = 0;
pthread_mutex_t accessReaderCnt = PTHREAD_MUTEX_INITIALIZER;//initializer
pthread_mutex_t accessWriterCnt = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t readerLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t outerLock = PTHREAD_MUTEX_INITIALIZER;//保证写者优先
void write1(){
	int rd = rand()%MAX_RAND;
	printf("write %d\n",rd);
	data = rd;
}
void read1(){
	printf("read %d\n",data);
}
void * writer(void * in){
	while(1){
		pthread_mutex_lock(&accessWriterCnt);//临界区,希望修改 writerCnt,独占 writerCnt
			writerCnt++;//此时可以访问writerCnt
			if(writerCnt == 1)//第一个写者	
				pthread_mutex_lock(&readerLock);//阻止后续的读者加入待读队列(写者优先)
		pthread_mutex_unlock(&accessWriterCnt);
		
		pthread_mutex_lock(&writeLock);//临界区，限制只有一个写者修改数据
			write1();
		pthread_mutex_unlock(&writeLock);
		
		pthread_mutex_lock(&accessWriterCnt);//临界区,希望修改 writerCnt,独占 writerCnt
			writerCnt--;
			if(writerCnt == 0)
				pthread_mutex_unlock(&readerLock);//后续的读者加入待读队列
		pthread_mutex_unlock(&accessWriterCnt);
		sleep(W_SLEEP);
	}
	pthread_exit((void *) 0);
      //pthread_exit(NULL);
}
 
void * reader (void * in){
	while(1){
		pthread_mutex_lock(&outerLock);//假如写者锁定了readerLock,那么成千上万的读者被锁在这里(写者优先)
		//临界区
			pthread_mutex_lock(&readerLock);//只被一个读者占有
			//临界区
				pthread_mutex_lock(&accessReaderCnt);
				//临界区
					readerCnt++;
					if(readerCnt == 1)
						pthread_mutex_lock(&writeLock);//有读者，阻塞写者
				pthread_mutex_unlock(&accessReaderCnt);
			pthread_mutex_unlock(&readerLock);//释放时,写者将优先获得readerLock
		pthread_mutex_unlock(&outerLock);
 
		read1();
		
		pthread_mutex_lock(&accessReaderCnt);//读者读完，释放readerCnt
		//临界区`
			readerCnt--;
			if(readerCnt == 0)
				pthread_mutex_unlock(&writeLock);//在最后一个并发读者读完这里开始，写者执行写操作
		pthread_mutex_unlock(&accessReaderCnt);
		sleep(R_SLEEP);
	}
	pthread_exit((void *) 0);
}
int main(){
	int i;
	for(i = 0; i < N_WRITER; i++)//2
		pthread_create(&wid[i],NULL,writer,NULL);
 	for(i = 0; i < N_READER; i++)//4
		pthread_create(&rid[i],NULL,reader,NULL);
	while(1)
		sleep(1000);
	return 0;
}
