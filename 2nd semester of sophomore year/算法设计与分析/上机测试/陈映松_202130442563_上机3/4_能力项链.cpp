#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
int n;
ll ans;
ll a[205];
struct f{
	int qian;
	int hou;
}zhu[205];
ll dp[205][205];//dp[i][j]表示从i到j的矩阵乘的代价 
ll Max(ll a,ll b){
	return a>b?a:b;
}
int main(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[n+i]=a[i];
	}
	for(int i=1;i<=n;i++){
		zhu[i].qian=a[i];
		zhu[i].hou=a[i+1];
	}
	zhu[n].qian=a[n];
	zhu[n].hou=a[1];
	for(int i=1;i<=n;i++)
		zhu[n+i].qian=zhu[i].qian,zhu[n+i].hou=zhu[i].hou;
	cout<<"这是珠子序列:"<<endl;
	for(int i=1;i<=2*n;i++)
		cout<<zhu[i].qian<<" "<<zhu[i].hou<<endl;
	for(int len=2;len<=n+1;len++){//len:长度(长度至少为2) 
			for(int left=1;left<=n;left++){//left:左区间 
			//for(int left=1;left+len-1<=2*n;left++){//left:左区间
				int right=len+left-1;//right:右区间 
				for(int k=left+1;k<=right-1;k++){
					ll temp=dp[left][k]+dp[k+1][right]+zhu[left].qian*zhu[k].hou*zhu[right].hou;
					if(temp>dp[left][right]) //这里需要最大化dp 
						dp[left][right]=temp;
				}
			} 
	}
	ll res=0;
	for(int i=1;i<=n;i++)//每个珠子都做一次开头,取max 
		res=Max(res,dp[i][n+i]);//dp[1][n+1],dp[2][n+2]..dp[n][2*n]
	cout<<res<<endl;
	return 0;
}
/*
7
23 17 212 113 71 301 33 
output:31182687
*/
