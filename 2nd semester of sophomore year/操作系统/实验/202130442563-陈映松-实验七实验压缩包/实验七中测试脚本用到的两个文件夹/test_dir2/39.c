#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#define MONKEY 10
#define TRUE 1
sem_t east_mutex, west_mutex, count_mutex;// 信号量创建
int count = 0;//共享变量，记录一个方向上正通过的猴子数量
void *monkey(void *direction) {
    int dir = *((int *) direction);//表示方向（0---to west，1--to east）
    while (TRUE) {  
        sem_wait(&count_mutex);// 进入临界区(count_mutex保证互斥访问count变量)
        count++;
        if (count == 1) // 如果当前是第一只狒狒，则需要先获取方向信号量      
            if (dir == 0) 
                sem_wait(&east_mutex);//上锁向东通行的可能，允许向西通行
            else 
                sem_wait(&west_mutex);//上锁向西通行的可能，允许向东通行
        sem_post(&count_mutex);      
        printf("Now Monkey from direction %d is crossing the rope\n", dir);  // 通过绳索      
        sem_wait(&count_mutex);// 离开临界区
        count--;
        if (count == 0) // 如果当前是最后一只狒狒，则需要释放方向信号量       
            if (dir == 0) //最后一只狒狒原来是向西通行的
                sem_post(&west_mutex);//允许向东通行
            else 
                sem_post(&east_mutex);//允许向西通行
        sem_post(&count_mutex);
        sleep(1);
    }
   pthread_exit(NULL);
}
int main() {
    sem_init(&east_mutex, 0, 1);//初始化信号量,第二个参数表示是否此信号量可共享，第三个参数表示资源数量
    sem_init(&west_mutex, 0, 1);//向西或者向东通行的狒狒同一时间只能有一个，故初始化为1
    sem_init(&count_mutex, 0, 1);//在绳索上的狒狒只能有一个
    pthread_t monkeys[MONKEY];
    int directions[MONKEY];
    for (int i = 0; i < MONKEY; i++) {
        directions[i] = rand() % 2;//随机指定一个方向前进
        pthread_create(&monkeys[i], NULL, monkey, &directions[i]);//创建狒狒线程
     }
    return 0;
}




