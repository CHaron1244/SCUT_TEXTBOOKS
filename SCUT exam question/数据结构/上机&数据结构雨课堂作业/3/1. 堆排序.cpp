#include<bits/stdc++.h>
using namespace std;
#define maxn 101
int a[maxn] ={0};
int b[maxn] ={0};
char c;
int pos=0;
int number=0;
int len=0;//��¼�ڵ���� 
int lastNumber;
void read(){
	if(c>='0'&&c<='9'){//������
		number = number*10 + c - '0';
	}
	else{//�ǿո� 
		a[pos++] = number;
		number = 0;
	} 
}
bool cmp(int a,int b){
	return a>b;
}
void heapify(int *arr,int n,int i){//����,����,��ά���ڵ���±�
	int min = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if(lson < n && arr[min] > arr[lson])//����С�ĺ��ӽ��
		min = lson;
	if(rson < n && arr[min] > arr[rson])//����С�ĺ��ӽ��
		min = rson;
	if(min != i){//�������� 
		swap(arr[min],arr[i]);
		heapify(arr,n,min);
	}	
} 
void heapSort(int *arr,int n){//��ʼ�±�Ϊ0 
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
	for(int i=0;i<len;i++)//���ս�� 
		cout<<b[i]<<" ";
	return 0;
} 
