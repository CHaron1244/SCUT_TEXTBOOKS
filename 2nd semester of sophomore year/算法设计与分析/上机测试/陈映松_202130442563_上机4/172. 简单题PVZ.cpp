#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false)
#define pb emplace_back

using namespace std;
const int maxn=2e5+100;
int n=6,m=9;
int mp[10];
int tmp[10];
int p[maxn];
int tol=0;
int getval(int x){
	int res=0;
	while(x){
		if(x&1){
			res+=1;
		}
		x>>=1;
	}
	return res;
}
void init(){
	for(int i=0;i<(1<<8);++i){
		if(i&(i<<1)||i&(i>>1)) continue;
		p[++tol]=i;
	}
}
int ans=1e9;
int boom[10];
int cnt=0;
void dfs(int cur,int sum){
	if(cur==6){
		++cnt;
		for(int i=1;i<=6;++i) tmp[i]=mp[i];
		for(int i=2;i<=5;++i){
			for(int j=i-1;j<=i+1;++j){
				tmp[j]|=boom[i];
				tmp[j]|=boom[i]<<1;
				tmp[j]|=boom[i]>>1;
			}
		}
		for(int i=1;i<=6;++i){
			if(tmp[i]!=(1<<9)-1) return;
		}
		ans=min(ans,sum);
		return;
	}
	int last=boom[cur-1];
	int w=150;
	if(cur==3||cur==4) w=175;
	for(int i=1;i<=tol;++i){
		if(p[i]&(last)||p[i]&(last<<1)||p[i]&(last>>1)) continue;
		boom[cur]=p[i];
		dfs(cur+1,sum+getval(p[i])*w);
	}
}
void solve(){
	for(int i=1;i<=6;++i){
		for(int j=1;j<=9;++j){
			int x;
			cin >> x;
			mp[i]*=2;
			mp[i]+=1-x;
		}
	}
	init();
	dfs(2,0);
	cout << ans;
}
int main(){
	int T=1;
	IOS;
	while(T--){ 
		solve();
	}
	
	
	return 0;
} 
