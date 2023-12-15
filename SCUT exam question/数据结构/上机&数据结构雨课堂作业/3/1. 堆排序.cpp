#include<bits/stdc++.h>
using namespace std;
#define maxn 101
int a[maxn] ={0};
int b[maxn] ={0};
char c;
int pos=0;
int number=0;
int len=0;//记录节点个数 
int lastNumber;
void read(){
	if(c>='0'&&c<='9'){//是数字
		number = number*10 + c - '0';
	}
	else{//是空格 
		a[pos++] = number;
		number = 0;
	} 
}
bool cmp(int a,int b){
	return a>b;
}
void heapify(int *arr,int n,int i){//数组,长度,待维护节点的下标
	int min = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if(lson < n && arr[min] > arr[lson])//找最小的孩子结点
		min = lson;
	if(rson < n && arr[min] > arr[rson])//找最小的孩子结点
		min = rson;
	if(min != i){//发生交换 
		swap(arr[min],arr[i]);
		heapify(arr,n,min);
	}	
} 
void heapSort(int *arr,int n){//初始下标为0 
	for(int i = n / 2 - 1;i >= 0; i--)
		heapify(arr,n,i);
}
int main()
{
	while((c=getchar())!=EOF)
		read();
	read();	
	for(int i =0;a[i]!=0;i++,len++);
	heapSort(a,len);
	for(int i=0;i<len;i++)	
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<len;i++)
		b[i] = a[i];
	sort(b,b+len,cmp);
	for(int i=0;i<len;i++)//最终结果 
		cout<<b[i]<<" ";
	return 0;
} 
