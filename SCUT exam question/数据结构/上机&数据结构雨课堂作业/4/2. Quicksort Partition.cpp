#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){	
		char c;
		int num=0;//�ݴ��������е���
		bool flag=0;
		int cnt=1;//���鳤�� 
		int a[1010];//�涨�����1��ʼ���� 
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
