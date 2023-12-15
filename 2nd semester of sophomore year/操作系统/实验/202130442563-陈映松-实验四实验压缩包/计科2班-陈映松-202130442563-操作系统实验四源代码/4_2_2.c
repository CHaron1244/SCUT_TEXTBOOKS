#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void) {
    int fd[2]; // fd[0]用于读取，fd[1]用于写入
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (pipe(fd) < 0) // 创建管道
        perror("pipe error");
    if ((pid = fork()) < 0) // fork出子进程
        perror("fork error");
    else if (pid == 0) { // 子进程
        close(fd[0]); // 关闭读端(这样保证正常写)
        char *msg = "Hello, you are my parent!\n";
        write(fd[1], msg, strlen(msg)); // 写入数据到管道
        exit(0);
     } 
    else { // 父进程
        close(fd[1]); // 关闭写端(这样保证正常读)
        int num_bytes = read(fd[0], buffer, BUFFER_SIZE); // 从管道读取数据
        if (num_bytes > 0) //message不为空
            printf("Received message from child: %s", buffer);
        exit(0);
     }
     return 0;
}

