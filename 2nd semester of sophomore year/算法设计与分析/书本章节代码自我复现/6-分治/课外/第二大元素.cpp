#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100];
int n;
int max;   //当前最大元素 
int f(int n)  
{
	int min;   //当前最小元素 
	if(n==2)     //只有两个元素时，直接求解（最小问题） 
	{
		if(a[n-2]>a[n-1])
			max=a[n-2],min=a[n-1];
		else
			max=a[n-1],min=a[n-2]; 
		return min;
	}
	else
	{ 
		min=f(n-1);		//递归找第二大元素 
		if(a[n-1]>max) min=max,max=a[n-1];   //找到前面n-1个元素中最大和第二大元素时
		if(a[n-1]<max&&a[n-1]>min) min=a[n-1]; //再与第n个元素比较找第二大元素 
		return min;   //返回结果 
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
	printf("请输入元素的个数n：");
	scanf("%d",&n);
	random();
	printf("\n这n个数依次为: ");
	for(int j=0;j<n;j++)
		printf("%d\t",a[j]);
	s=f(n);
	printf("\n\n这n个数中第二大元素为：%d\n",s);
	return 0;
}
