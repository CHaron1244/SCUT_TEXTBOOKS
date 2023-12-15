#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "config.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
 
// �����õ� put ������Ŀ��·��
char *getDesDir(char *cmsg)
{
     char *p;
     p=strtok(cmsg," ");
     p=strtok(NULL," ");
     return p;
}

// ��ȡָ������
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

// ����ͻ���ָ��
int cmd_handler(struct Msg msg,int fd)
{
      char *dir=NULL;
      char buf[32];
      int ret;
      int filefd;

      // ��ȡָ������
      ret=get_cmd_type(msg.cmd);

      switch(ret){
              case LS:
              case CD:
              case PWD:
                     // ���������������
                     msg.type=0;
                     write(fd,&msg,sizeof(msg));
                     break;
              case GET:
                     // ���������������
                     msg.type=2;
                     write(fd,&msg,sizeof(msg));
                     break;
              case PUT:
                     strcpy(buf,msg.cmd);
                     // �����õ�Ŀ��·��
                     dir=getDesDir(buf);

                     // �ж�Ŀ���ļ��Ƿ����
                     if(access(dir,F_OK) == -1){
                              printf("%s not exsit\n",dir);
                     }else{
                              filefd=open(dir,O_RDWR);
                              // ��Ŀ���ļ��ж�ȡ���ݣ����洢����Ϣ�� secondBuf �ֶ���
                              read(filefd,msg.secondBuf,sizeof(msg.secondBuf));
                              close(filefd);

                              // �������������Ϣ
                              write(fd,&msg,sizeof(msg));
                     }
                     break;
              case LLS:
                     // �ڿͻ�����ִ�� ls ����
                     system("ls");
                     break;
              case LCD:
                     // �ڿͻ�����ִ�� cd ����
                     dir=getDesDir(msg.cmd);
                     chdir(dir);
                     break;
              case QUIT:
                     // �����˳����󲢹رտͻ��˳���
                     strcpy(msg.cmd,"quit");
                     write(fd,&msg,sizeof(msg));
                     close(fd);
                     exit(-1);
      }
      return ret;
}

// �������Է���������Ϣ
void handler_server_message(int fd,struct Msg msg)
{
      int n_read;
      int new_file_fd;
      struct Msg msg_get;
      n_read=read(fd,&msg_get,sizeof(msg_get));//�ӷ�����������Ϣ

      // ������յ�����Ϣ����Ϊ 0����˵���������Ѿ��˳�����Ҫ�رտͻ��˳���
      if(n_read == 0){
               printf("server is out,quit\n");
               exit(-1);
      }

      // ������Ϣ���ͽ�����Ӧ�Ĵ���
      if(msg_get.type == DOFILE){
               char *p=getDesDir(msg.cmd);
               // ������д�뱾���ļ�
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

      struct sockaddr_in c_addr;//�ͻ��˲���Ҫbind��listen,accept,ֻ��һ���׽���
      struct Msg msg;

      if(argc != 3){
              printf("data error\n");
              exit(-1);
      }

      memset(&c_addr,0,sizeof(struct sockaddr_in));
      memset(&msg,0,sizeof(msg));

      c_fd=socket(AF_INET,SOCK_STREAM,0);//�����׽���
      if(c_fd == -1){
              perror("socket:");
              exit(-1);
      }

      c_addr.sin_family=AF_INET;//ȷ��Э��
      c_addr.sin_port=htons(atoi(argv[2]));//�˿�
      inet_aton(argv[1],&c_addr.sin_addr);//��ַ

      // ��������
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

              gets(msg.cmd);//��ȡָ��

              if(strlen(msg.cmd) == 0){
                    if(mark == 1){
                            printf(">");
                    }
                    continue;      
              }

              mark=1;

              int ret=cmd_handler(msg,c_fd);//����ָ���

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

              // �������Է���������Ϣ
              handler_server_message(c_fd,msg);
      }
      return 0;
}

