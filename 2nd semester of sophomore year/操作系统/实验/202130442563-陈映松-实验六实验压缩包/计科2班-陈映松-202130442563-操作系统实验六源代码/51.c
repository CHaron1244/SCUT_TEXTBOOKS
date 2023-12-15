#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INTERVAL 1000  //每隔1000次遍历输出缺页中断数目
#define ll long long
int cnt=0;	//缺页中断数目(记得每1000次要清0)
ll frame_number; //比如先设置为500(毕竟循环为1000)
/*
	frame_in_memory用来记录每个位置上的页框编号,-1表示还未使用
	frame_cnt表示每个位置上的这个页框的参数值
	frame_left表示当前还剩多少页框未使用
*/
int main(){
      FILE *fp;
      int arr[5050];
      fp = fopen("data_5000_1_800.txt", "r");  // 打开文件
      if (fp == NULL) {  // 检查文件是否成功打开
           printf("无法打开文件\n");
           return 1;
       }
      for (int i = 0; i < 5000; i++) 
           fscanf(fp, "%d", &arr[i]);  // 读取文件中的数据并记录在arr数组中
      fclose(fp);  // 关闭文件
	
	printf("请输入页框数量: ");
	scanf("%lld",&frame_number);
	printf("您输入的页框数量为: %d\n接下来开始遍历所有页面...\n",frame_number);
	unsigned int* frame_cnt;		//为每一个页框创建一个计数器,0 ~ 2的16次方-1(16位)
	frame_cnt = (unsigned int*) malloc(frame_number * sizeof(unsigned int));
	int* frame_in_memory;	//判断这个位置上有没有页面(-1不在，其余表示页框号)
	frame_in_memory = (int*) malloc(frame_number * sizeof(int));
	for(int i=0;i<frame_number;i++){
		frame_in_memory[i]=-1;
		frame_cnt[i]=0;
	}
	ll frame_left = frame_number;//当前还剩frame_number个页框未使用
	for(int p=0;p<5;p++){
	for(int i=0;i<INTERVAL;i++){
		for(int j=0;j<frame_number;j++)	//访问之前先除2
			frame_cnt[j] = frame_cnt[j] >> 1;
		int page_to_visit = arr[p*1000+i];
		//printf("请输入你想访问的页面号:  "); // page_to_visit>=1
		//scanf("%d",&page_to_visit);
		int pos_page_to_visit=0;//期望访问的页面号的地址
		bool flag=1;
		for(;pos_page_to_visit<frame_number;pos_page_to_visit++)
				if(frame_in_memory[pos_page_to_visit] == page_to_visit){
					flag=0;
					break;
				}			
		if(flag){//判断是否发生缺页
			//printf("发生缺页!!\n");
			cnt++;		//发送缺页则缺页中断数目加1
			//判断是否还有空余位置可以使用
			if(frame_left != 0){//还有空余页框
				//分配一个空余页框
				for(int k=0;k<frame_number;k++)
					if(frame_in_memory[k] == -1){//未使用
						frame_in_memory[k] = page_to_visit;//k号位置有页面了,调入此页面
						frame_cnt[k] = 2<<15;
						break;
					}
				frame_left--;
				//printf("这里frame_left--了!\n");
			}
			else{//无空余位置可以使用
				//使用老化算法调出一个页面
				//printf("这里发生了替换!\n");
				int Min = frame_cnt[0];
				int pos_to_exchange=0;
				for(int q=1;q<frame_number;q++)
					if(frame_cnt[q] < Min)
						pos_to_exchange = q;
				frame_in_memory[pos_to_exchange] = page_to_visit;//现在换出位置的页面是page_to_visit
				frame_cnt[pos_to_exchange] = 2<<15;
			}
		}
		else { //未发生缺页
			//当前访问页面参数-->右移1位 + 置最高位为1(way:加上2<<15,即32768)
			//其余页面参数--->直接右移1位 >>
			//printf("未发生缺页!!\n");
			frame_cnt[pos_page_to_visit] += 2<<15;
		}
	}
	printf("第%d次循环中缺页中断数为: %d\n",p+1,cnt);
	cnt=0;
	}
	printf("所有页面已经遍历完毕，结束程序...\n");
	return 0;
}
