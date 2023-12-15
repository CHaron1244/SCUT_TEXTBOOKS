#include<bits/stdc++.h>
using namespace std;
int a[25] ={0};
int len;//数的个数 
char c;
int sum=0; 
int cnt=0;
int pos=0;
int number=0;
void read(){
	if(c>='0'&&c<='9'){//是数字
		number = number*10 + c - '0';
	}
	else{//是空格 
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
		//想法:每次取两个最小的组成,然后每次取出来的两个树累加到sum中
		//直到数组中只有一个数 
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
