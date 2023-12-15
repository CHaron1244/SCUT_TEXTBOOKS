#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false)
#define pi acos(-1.0)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn=1e6+100;
using namespace std;
int n,m;
bool dp[maxn];
int cal(char ch){
	if(ch>='2'&&ch<='9'){
		return ch-'0';
	}
	if(ch=='A'){
		return 1;
	}
	if(ch=='1'){
		cin >> ch;
		return 10;
	}
	if(ch=='J') return 11;
	if(ch=='Q') return 12;
	if(ch=='K') return 13;
}
void solve(){
	cin >> n >> m;
	dp[0]=1;
	ll sum=0;
	int x; 
	for(int i=1;i<=n;++i){
		char ch;
		cin >> ch;
		x=cal(ch);
		sum+=x; 
		for(int j=m-1;j>=0;--j){
			dp[j+x]|=dp[j];
		}
	}
	for(int i=m;i<=m+13;++i){
		if(dp[i]){
			cout << sum-i;
			return;
		}
	}
	cout << "-1";
}
int main(){
	int T=1;
	IOS;
	while(T--){
		solve();
	}
	return 0;
}

