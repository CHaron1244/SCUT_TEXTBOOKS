#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<pthread.h> 
#include<windows.h>
pthread_t t1;           //pthread_t����t1�����ڻ�ȡ�߳�1��ID
pthread_t t2;           //pthread_t����t2�����ڻ�ȡ�߳�2��ID
pthread_rwlock_t rwlock;             //������д��
int data=1;                          //������Դ
void* readerM(void* arg)
{
	while(1)
	{
	pthread_rwlock_rdlock(&rwlock);    //���߼Ӷ���
	printf("M ���߶���: %d \n",data);   //��ȡ������Դ
	pthread_rwlock_unlock(&rwlock);    //�����ͷŶ���
	Sleep(1200);
	}
	return NULL;
}
void* readerN(void* arg)
{
	while(1)
	{
	pthread_rwlock_rdlock(&rwlock);
	printf(" N���߶���: %d \n",data);
	pthread_rwlock_unlock(&rwlock);
	Sleep(700);
	}
	return NULL;
}
void* writerA(void* arg)
{
	while(1)
	{
	pthread_rwlock_wrlock(&rwlock);      //д�߼�д��
	data++;                              //�Թ�����Դд����
	printf("	Aд��д��: %d\n",data);
	pthread_rwlock_unlock(&rwlock);      //�ͷ�д��
	Sleep(2000);
	}
	return NULL;
}
void* writerB(void* arg)
{
	while(1)
	{
	pthread_rwlock_wrlock(&rwlock);
	 data++;
	printf("	Bд��д��: %d\n",data);
	pthread_rwlock_unlock(&rwlock);
	Sleep(2000);
	}
	return NULL;
}
int main(int argc,char** argv)
{
	pthread_rwlock_init(&rwlock, NULL);   //��ʼ����д��
    
    pthread_create(&t1,NULL,readerM,NULL);
	pthread_create(&t1,NULL,readerN,NULL);
	pthread_create(&t2,NULL,writerA,NULL);
	pthread_create(&t2,NULL,writerB,NULL);

	pthread_rwlock_destroy(&rwlock);      //���ٶ�д��

	Sleep(10000000);
	return 0;
}



