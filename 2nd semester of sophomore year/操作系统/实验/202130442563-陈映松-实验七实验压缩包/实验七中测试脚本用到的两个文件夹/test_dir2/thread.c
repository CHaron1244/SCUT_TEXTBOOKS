#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<pthread.h> 
#include<windows.h>
pthread_t t1;           //pthread_t变量t1，用于获取线程1的ID
pthread_t t2;           //pthread_t变量t2，用于获取线程2的ID
pthread_rwlock_t rwlock;             //声明读写锁
int data=1;                          //共享资源
void* readerM(void* arg)
{
	while(1)
	{
	pthread_rwlock_rdlock(&rwlock);    //读者加读锁
	printf("M 读者读出: %d \n",data);   //读取共享资源
	pthread_rwlock_unlock(&rwlock);    //读者释放读锁
	Sleep(1200);
	}
	return NULL;
}
void* readerN(void* arg)
{
	while(1)
	{
	pthread_rwlock_rdlock(&rwlock);
	printf(" N读者读出: %d \n",data);
	pthread_rwlock_unlock(&rwlock);
	Sleep(700);
	}
	return NULL;
}
void* writerA(void* arg)
{
	while(1)
	{
	pthread_rwlock_wrlock(&rwlock);      //写者加写锁
	data++;                              //对共享资源写数据
	printf("	A写者写入: %d\n",data);
	pthread_rwlock_unlock(&rwlock);      //释放写锁
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
	printf("	B写者写入: %d\n",data);
	pthread_rwlock_unlock(&rwlock);
	Sleep(2000);
	}
	return NULL;
}
int main(int argc,char** argv)
{
	pthread_rwlock_init(&rwlock, NULL);   //初始化读写锁
    
    pthread_create(&t1,NULL,readerM,NULL);
	pthread_create(&t1,NULL,readerN,NULL);
	pthread_create(&t2,NULL,writerA,NULL);
	pthread_create(&t2,NULL,writerB,NULL);

	pthread_rwlock_destroy(&rwlock);      //销毁读写锁

	Sleep(10000000);
	return 0;
}



