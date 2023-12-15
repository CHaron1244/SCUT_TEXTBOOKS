#include<bits/stdc++.h>
using namespace std;
#define ll int 
#define max_len 5050  
ll a[max_len];
ll b[max_len];
ll dp[max_len][max_len];
ll n,m;//长度 
void fun(ll* x,ll* y){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(x[i]==y[j])
				dp[i][j] = 1+dp[i-1][j-1];
			else if(dp[i-1][j]>dp[i][j-1])
				dp[i][j]=dp[i-1][j];			
			else
				dp[i][j]=dp[i][j-1];			
	}
	cout<<dp[n][m]<<endl;
}
int main(){
	cin>>n>>m;//长度 
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=m;i++)
		cin>>b[i];
	fun(a,b);
	return 0;
}
