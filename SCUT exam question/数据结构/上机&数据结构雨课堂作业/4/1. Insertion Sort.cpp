#include<bits/stdc++.h>
using namespace std;
void insertSort(int *a,int len,int& sum){//数组下标:1-len 
	for(int i=2;i<=len;i++){//从第二个数开始看 
		int temp = a[i];
		int pos=1;
		for(int j=i;j>=1;j--){
			if(a[j] < a[i]){
				pos = j+1;
				break;
			}
		}
		for(int k=i-1;k>=pos;k--){
			a[k+1] = a[k];
			sum++;
		}
		a[pos] = temp;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int cnt=0;//数组长度 
		int sum=0;//最终结果 
		int a[1010];//规定数组从1开始计数 
		memset(a,0,sizeof(a));
		int num=0;//记录要存进数组的元素 
		bool flag=0;//判断负数 
		for(int i=0;i<s.length();i++){
			if(s[i]=='-')
				flag=1;
			else if(s[i]>='0'&&s[i]<='9')
				num=num*10+s[i]-'0';
			else if(s[i]==','){
				if(flag==1)
					num*=-1;
				a[++cnt] = num;		
				num=0;
				flag=0;
			}
		}
		if(flag==1)
			num*=-1;
		a[++cnt] = num;//最后还有一个数
		insertSort(a,cnt,sum);
		cout<<sum<<endl;
	}
	return 0;
} 
