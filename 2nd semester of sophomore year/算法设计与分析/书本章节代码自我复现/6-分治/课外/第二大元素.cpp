#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100];
int n;
int max;   //��ǰ���Ԫ�� 
int f(int n)  
{
	int min;   //��ǰ��СԪ�� 
	if(n==2)     //ֻ������Ԫ��ʱ��ֱ����⣨��С���⣩ 
	{
		if(a[n-2]>a[n-1])
			max=a[n-2],min=a[n-1];
		else
			max=a[n-1],min=a[n-2]; 
		return min;
	}
	else
	{ 
		min=f(n-1);		//�ݹ��ҵڶ���Ԫ�� 
		if(a[n-1]>max) min=max,max=a[n-1];   //�ҵ�ǰ��n-1��Ԫ�������͵ڶ���Ԫ��ʱ
		if(a[n-1]<max&&a[n-1]>min) min=a[n-1]; //�����n��Ԫ�رȽ��ҵڶ���Ԫ�� 
		return min;   //���ؽ�� 
	}
}
 
void random() 
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i]=1+rand()%100;
	}
}
 
int main(){	
	int s;
	printf("������Ԫ�صĸ���n��");
	scanf("%d",&n);
	random();
	printf("\n��n��������Ϊ: ");
	for(int j=0;j<n;j++)
		printf("%d\t",a[j]);
	s=f(n);
	printf("\n\n��n�����еڶ���Ԫ��Ϊ��%d\n",s);
	return 0;
}
