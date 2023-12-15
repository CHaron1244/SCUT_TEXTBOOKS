#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "config.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
 
// 解析得到 put 操作的目标路径
char *getDesDir(char *cmsg)
{
     char *p;
     p=strtok(cmsg," ");
     p=strtok(NULL," ");
     return p;
}

// 获取指令类型
int get_cmd_type(char *cmd)
{
     if(!strcmp("ls",cmd))         return LS;
     if(!strcmp("quit",cmd))       return QUIT;
     if(!strcmp("pwd",cmd))        return PWD;
     if(strstr(cmd,"cd") != NULL)  return CD;
     if(strstr(cmd,"get") != NULL) return GET;
     if(strstr(cmd,"put") != NULL) return PUT;
     if(!strcmp("lls",cmd))         return LLS;
     if(strstr(cmd,"lcd") != NULL) return LCD;

     return -1;
}

// 处理客户端指令
int cmd_handler(struct Msg msg,int fd)
{
      char *dir=NULL;
      char buf[32];
      int ret;
      int filefd;

      // 获取指令类型
      ret=get_cmd_type(msg.cmd);

      switch(ret){
              case LS:
              case CD:
              case PWD:
                     // 向服务器发送请求
                     msg.type=0;
                     write(fd,&msg,sizeof(msg));
                     break;
              case GET:
                     // 向服务器发送请求
                     msg.type=2;
                     write(fd,&msg,sizeof(msg));
                     break;
              case PUT:
                     strcpy(buf,msg.cmd);
                     // 解析得到目标路径
                     dir=getDesDir(buf);

                     // 判断目标文件是否存在
                     if(access(dir,F_OK) == -1){
                              printf("%s not exsit\n",dir);
                     }else{
                              filefd=open(dir,O_RDWR);
                              // 从目标文件中读取内容，并存储到消息的 secondBuf 字段中
                              read(filefd,msg.secondBuf,sizeof(msg.secondBuf));
                              close(filefd);

                              // 向服务器发送消息
                              write(fd,&msg,sizeof(msg));
                     }
                     break;
              case LLS:
                     // 在客户端上执行 ls 操作
                     system("ls");
                     break;
              case LCD:
                     // 在客户端上执行 cd 操作
                     dir=getDesDir(msg.cmd);
                     chdir(dir);
                     break;
              case QUIT:
                     // 发送退出请求并关闭客户端程序
                     strcpy(msg.cmd,"quit");
                     write(fd,&msg,sizeof(msg));
                     close(fd);
                     exit(-1);
      }
      return ret;
}

// 处理来自服务器的消息
void handler_server_message(int fd,struct Msg msg)
{
      int n_read;
      int new_file_fd;
      struct Msg msg_get;
      n_read=read(fd,&msg_get,sizeof(msg_get));//从服务器接收信息

      // 如果接收到的信息长度为 0，则说明服务器已经退出，需要关闭客户端程序
      if(n_read == 0){
               printf("server is out,quit\n");
               exit(-1);
      }

      // 根据消息类型进行相应的处理
      if(msg_get.type == DOFILE){
               char *p=getDesDir(msg.cmd);
               // 将数据写入本地文件
               new_file_fd=open(p,O_RDWR|O_CREAT|0600);
               write(new_file_fd,msg_get.cmd,strlen(msg_get.cmd));
               putchar('>');
               close(new_file_fd);
               fflush(stdout);
      }else{
               printf("................................\n");
               printf("\n%s\n",msg_get.cmd);
               printf("................................\n");
 
               putchar('>');
               fflush(stdout);
      }
}

int main(int argc,char **argv)
{
      int c_fd;

      struct sockaddr_in c_addr;//客户端不需要bind，listen,accept,只用一个套接字
      struct Msg msg;

      if(argc != 3){
              printf("data error\n");
              exit(-1);
      }

      memset(&c_addr,0,sizeof(struct sockaddr_in));
      memset(&msg,0,sizeof(msg));

      c_fd=socket(AF_INET,SOCK_STREAM,0);//建立套接字
      if(c_fd == -1){
              perror("socket:");
              exit(-1);
      }

      c_addr.sin_family=AF_INET;//确定协议
      c_addr.sin_port=htons(atoi(argv[2]));//端口
      inet_aton(argv[1],&c_addr.sin_addr);//地址

      // 申请连接
      if(connect(c_fd,(struct sockaddr *)&c_addr,sizeof(struct sockaddr_in)) == -1){
              perror("connect");
      }else{
              printf("connect ....\n");  
      } 

      int mark=0;
      while(1){
              memset(msg.cmd,0,sizeof(msg.cmd));
              if(mark == 0){
                     printf(">");
              }

              gets(msg.cmd);//获取指令

              if(strlen(msg.cmd) == 0){
                    if(mark == 1){
                            printf(">");
                    }
                    continue;      
              }

              mark=1;

              int ret=cmd_handler(msg,c_fd);//调用指令函数

              if(ret>IFGO){
                    putchar('>');
                    fflush(stdout);
                    continue;
              }
              if(ret == -1){
                    printf("command not\n");
                    fflush(stdout);
                    continue;
              }

              // 处理来自服务器的消息
              handler_server_message(c_fd,msg);
      }
      return 0;
}

