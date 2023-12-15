#include<bits/stdc++.h>
using namespace std;
#define ll int
#define maxn 1000010
ll w[maxn];
struct Q{
	int l;
	int r;
}qujian[maxn];
bool jizhan[maxn];
ll l[maxn];
ll n;
ll m; 
ll ans;
ll temp_left;
ll temp_right;
ll len;//记录端点不重叠的区间的个数 
int main(){
	cin>>n>>m;
	ll len=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
//	for(int i=1;i<=m;i++){
//		scanf("%lld",&temp_left);
//		scanf("%lld",&temp_right);
//		l[temp_right]=max(l[temp_right],temp_left);
//		if(temp_left==temp_right){//这个点必须选 
//			jizhan[i]=true;
//			ans+=w[temp_left];
//		}
//		else{//左右端点不同 
//			++len;
//			qujian[len].l = temp_left;
//			qujian[len].r = temp_right;
//		}
//	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&temp_left);
		scanf("%lld",&temp_right);
		l[temp_right]=max(l[temp_right],temp_left);
	}
	int Maxn=0;
	for(int i=1;i<=n;i++){
		l[i]=max(Maxn,l[i]);
		Maxn=max(Maxn,l[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<i<<"的最左端点是:"<<l[i]<<endl;
	cout<<"len="<<len<<endl;
	cout<<"ans="<<ans<<endl;
	return 0;
} 
//for(int j=k;j<=i-1;j++) k为最左端点 
//	dp[i]=min(dp[]+w[i],dp[i]);
/*
5 3
3 2 4 1 100
1 3
2 4 
5 5

5 3
7 3 4 2 2 
1 4 
2 3
4 5 
*/
