#include<bits/stdc++.h>
using namespace std;
int a[25] ={0};
int len;//���ĸ��� 
char c;
int sum=0; 
int cnt=0;
int pos=0;
int number=0;
void read(){
	if(c>='0'&&c<='9'){//������
		number = number*10 + c - '0';
	}
	else{//�ǿո� 
		a[pos++] = number;
		number = 0;
	} 
}
int findmin(int *a,int len){
	int temp=0;
	for(int i=1;i<len;i++)
		if(a[i]<a[temp])
			temp = i;
	return temp;
}
int main()
{
	while((c=getchar())!='\n'){
		read();
	}
	read();
	for(int i =0;a[i]!=0;i++,len++);
	queue<int>q;
	q.push(a[0]);
	while(!(q.empty())){
		//�뷨:ÿ��ȡ������С�����,Ȼ��ÿ��ȡ�������������ۼӵ�sum��
		//ֱ��������ֻ��һ���� 
		int temp1,temp2;
		cnt++;
		sort(a+cnt,a+len);
		temp1 =	a[findmin(a,len)];
		cnt++;
		sort(a+cnt,a+len);
		temp2 =	a[findmin(a,len)];
		sum+=(temp1+temp2);
	}
	return 0;
} 
