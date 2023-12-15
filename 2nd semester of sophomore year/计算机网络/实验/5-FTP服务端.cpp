#include <stdio.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "config.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
 
//获取客户端发送的命令中的目标路径
char *getDesDir(char *cmsg)
{
    char *p;
    p=strtok(cmsg," ");
    p=strtok(NULL," ");
    return p;
}
 
//获取指令类型
int get_cmd_type(char *cmd)
{
    if(!strcmp("ls",cmd))         return LS;
    if(!strcmp("quit",cmd))       return QUIT;
    if(!strcmp("pwd",cmd))        return PWD;
    if(strstr(cmd,"cd") != NULL)  return CD;
    if(strstr(cmd,"get") != NULL) return GET;
    if(strstr(cmd,"put") != NULL) return PUT; 
 
    return 100;         
}
 
//处理客户端发送的命令
void msg_handler(struct Msg msg,int fd)
{
    char cmdBuf[1024]={0};
    int ret;
    char *file=NULL;
    int fdfile;
    FILE *r=NULL;
 
    printf("smd:%s\n",msg.cmd);//打印指令
    ret=get_cmd_type(msg.cmd);
 
    switch(ret){
        case LS:
        case PWD:
            msg.type=0;
            r=popen(msg.cmd,"r");//popen可以将执行的结果写入指针r指向的地址中
            fread(msg.cmd,sizeof(msg.cmd),1,r);//将r中的内容度到msg.cmd中
            write(fd,&msg,sizeof(msg));//将结构体msg发送给客户端
            break;
        case CD:
            msg.type=1;
            char *dir=getDesDir(msg.cmd);
            printf("dir:%s\n",dir);
            chdir(dir);  //调用chdir（）函数移至此文件下
 
            break;
        case GET:
            file=getDesDir(msg.cmd);//找到要下载的文件名
 
            if(access(file,F_OK) == -1){ //access函数判断文件是否存在
                strcpy(msg.cmd,"No This File!");
                write(fd,&msg,sizeof(msg));//将提示信息发送给客户端
            }else{
                msg.type=DOFILE;
 
                fdfile=open(file,O_RDWR);//打开目标文件
                read(fdfile,cmdBuf,sizeof(cmdBuf));//将文件内容读到cmdBuf中
 
                strcpy(msg.cmd,cmdBuf);//复制文件
                write(fd,&msg,sizeof(msg));//将内容发送给客户端
            }
            break;
        case PUT:
            fdfile=open(getDesDir(msg.cmd),O_RDWR|O_CREAT|0666);
            write(fdfile,msg.secondBuf,strlen(msg.secondBuf));
            close(fdfile);
            break;
        case QUIT:
            printf("client quit!\n");
            exit(-1);
    }   
}
 
int main(int argc,char **argv)
{
    int s_fd;//监听套接字
    int c_fd;//连接套接字
    int n_read;
    int addrlen;
 
    struct sockaddr_in s_addr;//定义socket中的结构体
    struct sockaddr_in c_addr;//定义accept中的结构体
    struct Msg msg;//命令接收结构体
 
    memset(&s_addr,0,sizeof(struct sockaddr_in));
    memset(&c_addr,0,sizeof(struct sockaddr_in));
 
    if(argc != 3){
        printf("data error!");
        exit(-1);
    }
 
    s_fd=socket(AF_INET,SOCK_STREAM,0);//创建套接字并判断
    if(s_fd == -1){
        perror("socket:");
        exit(-1);
    }
 
    //确定TCP/IP协议
    s_addr.sin_family=AF_INET;
    //将端口号转变为网络字节序
    s_addr.sin_port=htons(atoi(argv[2]));
    //将地址转变为网络字节序
    inet_aton(argv[1],&s_addr.sin_addr);
 
    //给套接字添加信息
    bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));
 
    //监听，规定可以有10个客户端接入
    listen(s_fd,10);
 
    while(1){
        addrlen=sizeof(struct sockaddr_in);
        //阻塞等待连接并返回连接套接字
        c_fd=accept(s_fd,(struct sockaddr *)&c_addr,&addrlen);
        if(fork() == 0){ //进入子进程
            while(1){
                n_read=read(c_fd,&msg,sizeof(msg));//接收客户端发送的信息放入结构体msg中
                if(n_read == 0){
                    printf("client out\n");
                    break;
                }else{
                    msg_handler(msg,c_fd);//调用命令处理函数
                }        
            }
        }
    }
    close(c_fd);
    close(s_fd);
    return 0;
}

