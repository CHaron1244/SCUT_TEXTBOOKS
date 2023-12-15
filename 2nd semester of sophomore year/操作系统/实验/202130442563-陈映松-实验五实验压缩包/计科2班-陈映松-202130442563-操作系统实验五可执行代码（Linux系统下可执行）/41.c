#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define process_number 10
#define resource_number 10

int n,m;//n-->resource,m-->process
int allocation[process_number][resource_number];//�Ѿ�����
int max_need[process_number][resource_number];//�������
int need[process_number][resource_number];//��ǰ����
int available[resource_number];//������Դ
int work[resource_number];//��������
int finish[process_number];//�������

bool check(int i) { //������i�������Ƿ�С�ڵ���work����
    for (int j = 0; j < n; j++) //����ÿһ����Դj
        if (need[i][j] > work[j]) //����i����Դj���������
            return 0;           
    return 1;
}
void deadlock_detection(){
   int safe[m];   //��ȫ����
   int k=0;
   while (k < m) { //����ÿһ������
        int flag = 0;//�жϴ�״̬�Ƿ�ȫ
        for (int i = 0; i < m; i++) {//����ÿһ������
            if (finish[i] == 0 && check(i)) {//���i���̻�û��������(δ�����)���߽���i������С�ڵ���work����
                for (int j = 0; j < n; j++) //����ÿһ����Դ
                    work[j] += need[i][j];              
                finish[i] = 1;//i�����Ѿ����
                safe[k++] = i;//i�Ž����ǵڣ�k+1������ɵĽ���
                flag = 1;
               }
          }
        if(flag == 0){//ֻ������checkʧ��
           printf("NOT SAFE!ERROE!\n");
           return;
          }
     }     
    printf("OK!NOW IT IS SAFE!\n");//ÿһ�����̶��������
    for (int i = 0; i < m; i++) //�����ȫ����
        printf("%d ", safe[i]);
    printf("\n"); 
}
int main(){
   //printf("��������Դ��������");
   scanf("%d", &n);//��Դ������(<10)
   //printf("��������̵ĸ�����");
	scanf("%d", &m);//���̵ĸ���(<10)
	//printf("������ÿ����Դ��������");
	for (int i = 0; i < n; i++)//��ʼ��������Դ
        scanf("%d", &available[i]);  
   for (int i = 0; i < m; i++) {//����
        //printf("�������%d�����̵������������", i + 1);
        for (int j = 0; j < n; j++)  //��Դ       
            scanf("%d", &max_need[i][j]);//��ʼ���������
    }
   for (int i = 0; i < m; i++) {//����
        //printf("�������%d�������Ѿ��������Դ����", i + 1);
        for (int j = 0; j < n; j++) { //��Դ       
            scanf("%d", &allocation[i][j]);//��ʼ���Ѿ�����
            need[i][j] = max_need[i][j] - allocation[i][j];//��ǰ����=�������-�Ѿ�����
          }
    }
    for (int i = 0; i < n; i++) // ��ʼ����������
        work[i] = available[i];
    for (int i = 0; i < m; i++) // ��ʼ���������
        finish[i] = 0;
    deadlock_detection();
    return 0;
}
