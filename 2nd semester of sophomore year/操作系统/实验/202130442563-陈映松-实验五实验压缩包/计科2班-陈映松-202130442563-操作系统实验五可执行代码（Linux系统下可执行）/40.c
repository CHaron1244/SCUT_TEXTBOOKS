#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MONKEY 10  
#define NUMBER 3   //绳索的最大容量
#define TRUE 1
int east_count = 0;  //向东狒狒数量
int west_count = 0;  //向西狒狒数量
sem_t rope_mutex;
sem_t east_monkey;
sem_t west_monkey;  //绳索互斥信号量,向东的狒狒信号量,向西的狒狒信号量
void *monkey(void *direction) {
    int dir = *(int*)direction;
    int opposite_dir = (dir == 1) ? 0 : 1;//反方向
    while (TRUE) {
        sem_wait(&rope_mutex); // 等待通过绳索的机会
          // 检查是否有与当前方向相反的狒狒在绳索,如果没有，则狒狒可以通过绳索
        if ((dir == 1 && west_count == 0) || (dir == 0 && east_count == 0)) {   
            if (dir == 1) {
                west_count++;
                sem_post(&west_monkey);
          	   } 
            else {
                east_count++;
                sem_post(&east_monkey);
            	}
         		sem_post(&rope_mutex);// 释放绳索互斥信号量
         		printf("Monkey from direction %d is crossing the rope!\n", dir);// 狒狒通过绳索
                // 等待足够多的狒狒通过绳索，以便向相反方向的狒狒可以通过
            if (dir == 1) {
                sem_wait(&east_monkey);
                east_count--;
            	} 
            else {
                sem_wait(&west_monkey);
                west_count--;
            	}
        		printf("Monkey %d left the rope.\n", dir);// 狒狒离开绳索
          } 
        else 
        	   sem_post(&rope_mutex);// 如果绳子上有猴子，则等待绳索空闲
    }
}
int main() {
    pthread_t monkeys[MONKEY];
    int direction[MONKEY];
    sem_init(&rope_mutex, 0, NUMBER);// 初始化信号量
    sem_init(&east_monkey, 0, 0);
    sem_init(&west_monkey, 0, 0);
    for (int i = 0; i < MONKEY; i++) {// 创建狒狒线程
        direction[i] = rand() % 2;  // 随机选择向东或向西
        pthread_create(&monkeys[i], NULL, monkey, &direction[i]);
    } 
    for (int i = 0; i < MONKEY; i++) // 等待所有线程结束
        pthread_join(monkeys[i], NULL);    
}

