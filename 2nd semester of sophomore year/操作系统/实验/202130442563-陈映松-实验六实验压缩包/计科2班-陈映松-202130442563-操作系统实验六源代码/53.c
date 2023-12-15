#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 1000000
int main() {
    int array[ARRAY_SIZE];
    clock_t init = clock();// 每次使用clock前都需要初始化时钟
    clock_t start1 = clock();// 记录TLB命中情况下的读取时间
    for (int i = 0; i < ARRAY_SIZE; i++) 
        array[i] = i;   
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) * 1000.0 / CLOCKS_PER_SEC;
    clock_t start2 = clock();// 记录TLB未命中情况下的读取时间
    for (int i = 0; i < ARRAY_SIZE; i += 4096) 
        array[i] = i; 
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) * 1000.0 / CLOCKS_PER_SEC;
    printf("TLB 命中时时间长度:%.6f毫秒\n", time1);
    printf("TLB 不命中时时间长度:%.6f毫秒\n", time2);
    return 0;
}

