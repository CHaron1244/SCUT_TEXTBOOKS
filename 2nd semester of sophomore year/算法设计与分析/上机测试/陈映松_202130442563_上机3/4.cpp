#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
int n;
ll ans;
ll a[205];//�����ģ
ll dp[205][205];
ll Max(ll a,ll b){
	return a>b?a:b;
}
int main(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=n;i++){//����һ������Ϊ2*n������,�������±�1-n��ͷ���ܹ���ѭ��,eg:dp[1][n+1],dp[2][n+2]..dp[n+1][2*n]
		scanf("%lld",&a[i]);
		a[n+i]=a[i];
	}
    for(ll i=2;i<=n+1;i++){//i:���� 
        for(ll l=1;l+i-1<=2*n;l++){  //l:��˵�.�����ȡ���������ԣ�һ��Ҫ��2*n���㶼����     
            ll r=l+i-1;//r:�Ҷ˵� 
            for(ll k=l+1;k<=r-1;k++) // l < k < r
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]); 
        }
    }
    ll res=0;
    for (ll i=1;i<=n;i++) //ÿ�����Ӷ���һ�ο�ͷ,ȡmax 
		res=Max(res,dp[i][n+i]);//dp[1][n+1],dp[2][n+2]..dp[n][2*n]
    cout<<res<<endl;
}
