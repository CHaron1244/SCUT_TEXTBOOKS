#include "stdio.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
#define N_WRITER 3 //写者数目
#define N_READER 4 //读者数目
#define W_SLEEP  1 //控制写频率
#define R_SLEEP  1 //控制读频率
 
pthread_t wid[N_WRITER],rid[N_READER];
const int MAX_RAND = 10;//产生的最大随机数
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;//同一时间只能一个人写文件,互斥
pthread_mutex_t accessReaderCnt = PTHREAD_MUTEX_INITIALIZER;//同一时间只能有一个人访问 readerCnt
int data = 0;
int readerCnt = 0;
void write(){
	int rd = rand() % MAX_RAND;
	printf("write %d\n",rd);
	data = rd;
}
void read(){
	printf("read %d\n",data);
}
void * writer(void * in){
	while(1){
		pthread_mutex_lock(&writeLock);//同一时间只能一个人写文件,互斥(需要lock) 
		write();
		pthread_mutex_unlock(&writeLock);
		sleep(W_SLEEP);
	}
	pthread_exit((void *) 0);
	//pthread_exit(NULL);
}
 
void * reader (void * in){
	while(1){
		pthread_mutex_lock(&accessReaderCnt);//先看能不能访问readercnt 
		readerCnt++;//能访问readercnt,则加1 
		if(readerCnt == 1)
			pthread_mutex_lock(&writeLock);//不允许写者进程 
		pthread_mutex_unlock(&accessReaderCnt);
		
		read();
		
		pthread_mutex_lock(&accessReaderCnt);
		readerCnt--;
		if(readerCnt == 0)
			pthread_mutex_unlock(&writeLock);
		pthread_mutex_unlock(&accessReaderCnt);
		sleep(R_SLEEP);
	}
	pthread_exit((void *) 0);
}
int main(){
	int i = 0;
	for(i = 0; i < N_READER; i++)//3	
		pthread_create(&wid[i],NULL,reader,NULL);	
	for(i = 0; i < N_WRITER; i++)//3	
		pthread_create(&rid[i],NULL,writer,NULL);
	while(1)
		sleep(10);
	return 0;
}
