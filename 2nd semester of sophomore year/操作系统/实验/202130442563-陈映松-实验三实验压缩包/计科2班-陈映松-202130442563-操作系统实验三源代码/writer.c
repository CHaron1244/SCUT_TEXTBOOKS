#include "stdio.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N_WRITER 2 //д����Ŀ
#define N_READER 4 //������Ŀ
#define W_SLEEP 1 //����дʱ����
#define R_SLEEP  1 //���ƶ�ʱ����
 
pthread_t wid[N_WRITER],rid[N_READER];
const int MAX_RAND = 100;//��������������
int data = 0;
int readerCnt = 0, writerCnt = 0;
pthread_mutex_t accessReaderCnt = PTHREAD_MUTEX_INITIALIZER;//initializer
pthread_mutex_t accessWriterCnt = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t readerLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t outerLock = PTHREAD_MUTEX_INITIALIZER;//��֤д������
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
		pthread_mutex_lock(&accessWriterCnt);//�ٽ���,ϣ���޸� writerCnt,��ռ writerCnt
			writerCnt++;//��ʱ���Է���writerCnt
			if(writerCnt == 1)//��һ��д��	
				pthread_mutex_lock(&readerLock);//��ֹ�����Ķ��߼����������(д������)
		pthread_mutex_unlock(&accessWriterCnt);
		
		pthread_mutex_lock(&writeLock);//�ٽ���������ֻ��һ��д���޸�����
			write1();
		pthread_mutex_unlock(&writeLock);
		
		pthread_mutex_lock(&accessWriterCnt);//�ٽ���,ϣ���޸� writerCnt,��ռ writerCnt
			writerCnt--;
			if(writerCnt == 0)
				pthread_mutex_unlock(&readerLock);//�����Ķ��߼����������
		pthread_mutex_unlock(&accessWriterCnt);
		sleep(W_SLEEP);
	}
	pthread_exit((void *) 0);
      //pthread_exit(NULL);
}
 
void * reader (void * in){
	while(1){
		pthread_mutex_lock(&outerLock);//����д��������readerLock,��ô��ǧ����Ķ��߱���������(д������)
		//�ٽ���
			pthread_mutex_lock(&readerLock);//ֻ��һ������ռ��
			//�ٽ���
				pthread_mutex_lock(&accessReaderCnt);
				//�ٽ���
					readerCnt++;
					if(readerCnt == 1)
						pthread_mutex_lock(&writeLock);//�ж��ߣ�����д��
				pthread_mutex_unlock(&accessReaderCnt);
			pthread_mutex_unlock(&readerLock);//�ͷ�ʱ,д�߽����Ȼ��readerLock
		pthread_mutex_unlock(&outerLock);
 
		read1();
		
		pthread_mutex_lock(&accessReaderCnt);//���߶��꣬�ͷ�readerCnt
		//�ٽ���`
			readerCnt--;
			if(readerCnt == 0)
				pthread_mutex_unlock(&writeLock);//�����һ���������߶������￪ʼ��д��ִ��д����
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
