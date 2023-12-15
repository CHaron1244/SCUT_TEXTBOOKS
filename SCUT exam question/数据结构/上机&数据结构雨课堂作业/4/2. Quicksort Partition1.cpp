#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){	
		char c;
		int num=0;//暂存存进数组中的数
		bool flag=0;
		int cnt=1;//数组长度 
		int a[1010];//规定数组从1开始计数 
		memset(a,0,sizeof(a));
		cin>>a[1];
		while(cin.get()!='\n')
			cin>>a[++cnt];
		int lastNum = a[cnt];
		sort(a+1,a+cnt+1);
		for(int i =1;i<=cnt;i++)
			if(a[i]==lastNum){
				cout<<i-1<<endl;
			}		
	}
	return 0;
}
