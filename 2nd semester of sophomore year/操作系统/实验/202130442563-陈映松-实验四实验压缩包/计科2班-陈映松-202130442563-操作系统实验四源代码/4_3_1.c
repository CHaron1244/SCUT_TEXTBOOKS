#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#define SIZE 1024 // 共享内存区域的大小
int main() {
    key_t key = 1234; // 共享内存区域的key
    int shmid;
    char *data; // 指向共享内存区域的指针
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) // 创建共享内存区域
        perror("shmget");
    if ((data = shmat(shmid, NULL, 0)) == (char *) -1)  // 连接到共享内存区域
        perror("shmat");
    sprintf(data, "Hello, world!");// 主进程写入数据到共享内存区域
    pid_t pid1 = fork();// 创建子进程
    pid_t pid2 = fork();

    if (pid1 == -1 || pid2 == -1) 
        perror("fork");
    else if (pid1 == 0 && pid2 > 0) { // 子进程1
        if ((data = shmat(shmid, NULL, 0)) == (char *) -1) // 连接到共享内存区域
            perror("shmat");
        // 读取共享内存区域中的数据并输出
        printf("Data in shared memory from process 1: %s\n", data);
        // 修改共享内存区域中的数据
        sprintf(data, "Hello from process 1!");
        // 分离共享内存区域
        if (shmdt(data) == -1) 
            perror("shmdt");
    } 
   else if (pid1 > 0 && pid2 == 0) { // 子进程2
        // 连接到共享内存区域
        if ((data = shmat(shmid, NULL, 0)) == (char *) -1)
            perror("shmat");
        // 读取共享内存区域中的数据并输出
        printf("Data in shared memory from process 2: %s\n", data);
        // 修改共享内存区域中的数据
        sprintf(data, "Hello from process 2!");
        // 分离共享内存区域
        if (shmdt(data) == -1) 
            perror("shmdt");
    } 
   else { // 父进程
        wait(NULL);// 等待子进程结束
        wait(NULL);
        // 读取共享内存区域中的数据并输出
        printf("Data in shared memory from parent process: %s\n", data);
        // 分离共享内存区域
        if (shmdt(data) == -1) 
            perror("shmdt");
        // 删除共享内存区域
        if (shmctl(shmid, IPC_RMID, NULL) == -1) 
        perror("shmctl");
     }
    exit(0);
}
