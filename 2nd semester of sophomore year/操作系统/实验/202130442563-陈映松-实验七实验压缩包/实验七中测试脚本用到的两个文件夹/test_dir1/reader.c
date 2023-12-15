#include "stdio.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
#define N_WRITER 3 //д����Ŀ
#define N_READER 4 //������Ŀ
#define W_SLEEP  1 //����дƵ��
#define R_SLEEP  1 //���ƶ�Ƶ��
 
pthread_t wid[N_WRITER],rid[N_READER];
const int MAX_RAND = 10;//��������������
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;//ͬһʱ��ֻ��һ����д�ļ�,����
pthread_mutex_t accessReaderCnt = PTHREAD_MUTEX_INITIALIZER;//ͬһʱ��ֻ����һ���˷��� readerCnt
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
		pthread_mutex_lock(&writeLock);//ͬһʱ��ֻ��һ����д�ļ�,����(��Ҫlock) 
		write();
		pthread_mutex_unlock(&writeLock);
		sleep(W_SLEEP);
	}
	pthread_exit((void *) 0);
	//pthread_exit(NULL);
}
 
void * reader (void * in){
	while(1){
		pthread_mutex_lock(&accessReaderCnt);//�ȿ��ܲ��ܷ���readercnt 
		readerCnt++;//�ܷ���readercnt,���1 
		if(readerCnt == 1)
			pthread_mutex_lock(&writeLock);//������д�߽��� 
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
