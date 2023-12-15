#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void *f(void* num){
	printf("hello\n");
	for(int i=0;i<100;i++){
		printf("i = %d\n",i);
	}
}
int main(){
	pthread_t pid;
	pthread_create(&pid,NULL,f,NULL);
	usleep(10);
	printf("123\n1243\n");
}
//gcc temp.c -o temp -lpthread
