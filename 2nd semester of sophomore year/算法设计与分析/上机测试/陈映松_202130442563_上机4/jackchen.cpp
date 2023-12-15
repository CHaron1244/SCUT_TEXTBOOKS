#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll maxn=1e5+10;
ll n;//城市数量 1<=n<=1e5
ll m;//边数量  0<=m<=2e5
vector<ll> arr[maxn];
ll in[maxn];//入度
//ll out[maxn];//出度 
int vis[maxn];
queue<ll>q;
ll cnt[maxn];
ll ans;
void solve(){
	for(int i=1;i<=n;i++)//放起点 
		if(in[i]==0&&arr[i].size()!=0){//有出边没有入边(并且只有一个点不算) 
			q.push(i);
			cnt[i]=1;
		}
	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		for(auto j:arr[temp]){//temp指向j 
			if(in[j]!=0){//不是起点 
				cnt[j]+=cnt[temp];
				in[j]--;
			}
			if(in[j]==0)//作为起点 
				q.push(j);
		}
		if(arr[temp].size()==0)//终点 
			ans+=cnt[temp];
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	ll u,v;
	for(ll i=1;i<=m;i++){
		cin>>u>>v;
		arr[u].push_back(v);
		//out[u]++;//有边离开u 
		in[v]++;//有边进入v 
	}
	solve();
	cout<<ans<<endl;
	return 0;
} 
