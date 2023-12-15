#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
int n;
ll ans;
ll a[205];//矩阵规模
ll dp[205][205];
ll Max(ll a,ll b){
	return a>b?a:b;
}
int main(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=n;i++){//构造一个长度为2*n的数组,其中以下标1-n开头都能构成循环,eg:dp[1][n+1],dp[2][n+2]..dp[n+1][2*n]
		scanf("%lld",&a[i]);
		a[n+i]=a[i];
	}
    for(ll i=2;i<=n+1;i++){//i:长度 
        for(ll l=1;l+i-1<=2*n;l++){  //l:左端点.如果采取了上述策略，一定要将2*n个点都更新     
            ll r=l+i-1;//r:右端点 
            for(ll k=l+1;k<=r-1;k++) // l < k < r
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]); 
        }
    }
    ll res=0;
    for (ll i=1;i<=n;i++) //每个珠子都做一次开头,取max 
		res=Max(res,dp[i][n+i]);//dp[1][n+1],dp[2][n+2]..dp[n][2*n]
    cout<<res<<endl;
}
