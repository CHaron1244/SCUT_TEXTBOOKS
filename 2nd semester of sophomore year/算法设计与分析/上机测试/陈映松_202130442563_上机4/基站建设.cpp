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
ll len;//��¼�˵㲻�ص�������ĸ��� 
int main(){
	cin>>n>>m;
	ll len=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
//	for(int i=1;i<=m;i++){
//		scanf("%lld",&temp_left);
//		scanf("%lld",&temp_right);
//		l[temp_right]=max(l[temp_right],temp_left);
//		if(temp_left==temp_right){//��������ѡ 
//			jizhan[i]=true;
//			ans+=w[temp_left];
//		}
//		else{//���Ҷ˵㲻ͬ 
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
		cout<<i<<"������˵���:"<<l[i]<<endl;
	cout<<"len="<<len<<endl;
	cout<<"ans="<<ans<<endl;
	return 0;
} 
//for(int j=k;j<=i-1;j++) kΪ����˵� 
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
