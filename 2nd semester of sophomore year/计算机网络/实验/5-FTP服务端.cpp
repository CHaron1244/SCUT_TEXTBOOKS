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
 
//��ȡ�ͻ��˷��͵������е�Ŀ��·��
char *getDesDir(char *cmsg)
{
    char *p;
    p=strtok(cmsg," ");
    p=strtok(NULL," ");
    return p;
}
 
//��ȡָ������
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
 
//����ͻ��˷��͵�����
void msg_handler(struct Msg msg,int fd)
{
    char cmdBuf[1024]={0};
    int ret;
    char *file=NULL;
    int fdfile;
    FILE *r=NULL;
 
    printf("smd:%s\n",msg.cmd);//��ӡָ��
    ret=get_cmd_type(msg.cmd);
 
    switch(ret){
        case LS:
        case PWD:
            msg.type=0;
            r=popen(msg.cmd,"r");//popen���Խ�ִ�еĽ��д��ָ��rָ��ĵ�ַ��
            fread(msg.cmd,sizeof(msg.cmd),1,r);//��r�е����ݶȵ�msg.cmd��
            write(fd,&msg,sizeof(msg));//���ṹ��msg���͸��ͻ���
            break;
        case CD:
            msg.type=1;
            char *dir=getDesDir(msg.cmd);
            printf("dir:%s\n",dir);
            chdir(dir);  //����chdir���������������ļ���
 
            break;
        case GET:
            file=getDesDir(msg.cmd);//�ҵ�Ҫ���ص��ļ���
 
            if(access(file,F_OK) == -1){ //access�����ж��ļ��Ƿ����
                strcpy(msg.cmd,"No This File!");
                write(fd,&msg,sizeof(msg));//����ʾ��Ϣ���͸��ͻ���
            }else{
                msg.type=DOFILE;
 
                fdfile=open(file,O_RDWR);//��Ŀ���ļ�
                read(fdfile,cmdBuf,sizeof(cmdBuf));//���ļ����ݶ���cmdBuf��
 
                strcpy(msg.cmd,cmdBuf);//�����ļ�
                write(fd,&msg,sizeof(msg));//�����ݷ��͸��ͻ���
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
    int s_fd;//�����׽���
    int c_fd;//�����׽���
    int n_read;
    int addrlen;
 
    struct sockaddr_in s_addr;//����socket�еĽṹ��
    struct sockaddr_in c_addr;//����accept�еĽṹ��
    struct Msg msg;//������սṹ��
 
    memset(&s_addr,0,sizeof(struct sockaddr_in));
    memset(&c_addr,0,sizeof(struct sockaddr_in));
 
    if(argc != 3){
        printf("data error!");
        exit(-1);
    }
 
    s_fd=socket(AF_INET,SOCK_STREAM,0);//�����׽��ֲ��ж�
    if(s_fd == -1){
        perror("socket:");
        exit(-1);
    }
 
    //ȷ��TCP/IPЭ��
    s_addr.sin_family=AF_INET;
    //���˿ں�ת��Ϊ�����ֽ���
    s_addr.sin_port=htons(atoi(argv[2]));
    //����ַת��Ϊ�����ֽ���
    inet_aton(argv[1],&s_addr.sin_addr);
 
    //���׽��������Ϣ
    bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));
 
    //�������涨������10���ͻ��˽���
    listen(s_fd,10);
 
    while(1){
        addrlen=sizeof(struct sockaddr_in);
        //�����ȴ����Ӳ����������׽���
        c_fd=accept(s_fd,(struct sockaddr *)&c_addr,&addrlen);
        if(fork() == 0){ //�����ӽ���
            while(1){
                n_read=read(c_fd,&msg,sizeof(msg));//���տͻ��˷��͵���Ϣ����ṹ��msg��
                if(n_read == 0){
                    printf("client out\n");
                    break;
                }else{
                    msg_handler(msg,c_fd);//�����������
                }        
            }
        }
    }
    close(c_fd);
    close(s_fd);
    return 0;
}

