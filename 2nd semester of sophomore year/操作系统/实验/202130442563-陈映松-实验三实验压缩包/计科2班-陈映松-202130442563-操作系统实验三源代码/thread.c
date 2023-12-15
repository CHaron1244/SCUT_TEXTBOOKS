#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10
#define MAX_RAND 100
#define TRUE 1
#define FALSE 0

//int buffer[N];
int data=0; //共享数据
int cnt=0; //记录缓冲区中的元素个数
pthread_t pid[5],cid[5];

void produce_item(){
	int rd = rand()%MAX_RAND;
	printf("write %d\n",rd);
	data = rd;
}
void remove_item(){
	printf("read %d\n",data);
}
void* producer(void * arg){
	int item;
	while(TRUE){
		produce_item();
		if(cnt==N)
			sleep(5);
		cnt++;
		//if(cnt==1)
			//wakeup(consumer);
	}
	pthread_exit((void*)0);
	//pthread_exit(NULL);
}
void* consumer(void * arg){
	int item;
	while(TRUE){
		if(cnt==0)
			sleep(5);
		remove_item();
		cnt--;
		//if(cnt==N-1)
			//wakeup(producer);
	}
	pthread_exit((void*)0);
}
int main(){
	int i;
	for(i=0;i<=5;i++)
		pthread_create(&pid[i],NULL,producer,NULL);
	for(i=0;i<=5;i++)
		pthread_create(&cid[i],NULL,consumer,NULL);
	return 0;
}
