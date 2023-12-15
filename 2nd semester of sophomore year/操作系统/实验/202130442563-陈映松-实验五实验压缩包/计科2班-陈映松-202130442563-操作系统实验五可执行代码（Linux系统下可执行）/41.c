#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define process_number 10
#define resource_number 10

int n,m;//n-->resource,m-->process
int allocation[process_number][resource_number];//已经分配
int max_need[process_number][resource_number];//最大需求
int need[process_number][resource_number];//当前需求
int available[resource_number];//可用资源
int work[resource_number];//工作向量
int finish[process_number];//完成向量

bool check(int i) { //检查进程i的需求是否小于等于work向量
    for (int j = 0; j < n; j++) //对于每一种资源j
        if (need[i][j] > work[j]) //进程i对资源j的需求过大
            return 0;           
    return 1;
}
void deadlock_detection(){
   int safe[m];   //安全序列
   int k=0;
   while (k < m) { //对于每一个进程
        int flag = 0;//判断此状态是否安全
        for (int i = 0; i < m; i++) {//对于每一个进程
            if (finish[i] == 0 && check(i)) {//如果i进程还没有运行完(未被标记)或者进程i的需求小于等于work向量
                for (int j = 0; j < n; j++) //对于每一种资源
                    work[j] += need[i][j];              
                finish[i] = 1;//i进程已经完成
                safe[k++] = i;//i号进程是第（k+1）个完成的进程
                flag = 1;
               }
          }
        if(flag == 0){//只可能是check失败
           printf("NOT SAFE!ERROE!\n");
           return;
          }
     }     
    printf("OK!NOW IT IS SAFE!\n");//每一个进程都运行完毕
    for (int i = 0; i < m; i++) //输出安全序列
        printf("%d ", safe[i]);
    printf("\n"); 
}
int main(){
   //printf("请输入资源的种数：");
   scanf("%d", &n);//资源的种数(<10)
   //printf("请输入进程的个数：");
	scanf("%d", &m);//进程的个数(<10)
	//printf("请输入每种资源的数量：");
	for (int i = 0; i < n; i++)//初始化可用资源
        scanf("%d", &available[i]);  
   for (int i = 0; i < m; i++) {//进程
        //printf("请输入第%d个进程的最大需求量：", i + 1);
        for (int j = 0; j < n; j++)  //资源       
            scanf("%d", &max_need[i][j]);//初始化最大需求
    }
   for (int i = 0; i < m; i++) {//进程
        //printf("请输入第%d个进程已经分配的资源数：", i + 1);
        for (int j = 0; j < n; j++) { //资源       
            scanf("%d", &allocation[i][j]);//初始化已经分配
            need[i][j] = max_need[i][j] - allocation[i][j];//当前需求=最大需求-已经分配
          }
    }
    for (int i = 0; i < n; i++) // 初始化工作向量
        work[i] = available[i];
    for (int i = 0; i < m; i++) // 初始化完成向量
        finish[i] = 0;
    deadlock_detection();
    return 0;
}
