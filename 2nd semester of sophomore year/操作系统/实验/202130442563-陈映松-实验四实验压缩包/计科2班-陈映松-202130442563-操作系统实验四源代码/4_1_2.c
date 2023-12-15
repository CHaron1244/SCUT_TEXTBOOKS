#include <stdio.h>
#include <signal.h>
#include <unistd.h>

pid_t pid;//同pthread_t

void kill_fun(int num){
	printf("It is being killed!\n");
	kill(getpid(),SIGILL);
}

int main(){
	pid = fork();//创建进程，pid记录返回值
	if(pid < 0){
		printf("ERROR!\n");
	}
	else if(pid == 0){ //pid等于0，生成子进程
		printf("It is creating a child_process,pid = %d\n",getpid());
		while(1){
			printf("processing...\n");//子进程运行
			sleep(1);
			signal(SIGUSR1,kill_fun);//被杀死，返回以前的信号处理函数的地址
		}
	}
	else{//父进程
		sleep(2);
		kill(pid,SIGUSR1);//杀死子进程
		printf("father_process's id = %d,killing child_process!\n",getpid());
	}
	return 0;
}
