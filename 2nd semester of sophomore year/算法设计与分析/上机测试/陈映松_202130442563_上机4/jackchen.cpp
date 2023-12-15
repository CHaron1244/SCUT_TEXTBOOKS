#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll maxn=1e5+10;
ll n;//�������� 1<=n<=1e5
ll m;//������  0<=m<=2e5
vector<ll> arr[maxn];
ll in[maxn];//���
//ll out[maxn];//���� 
int vis[maxn];
queue<ll>q;
ll cnt[maxn];
ll ans;
void solve(){
	for(int i=1;i<=n;i++)//����� 
		if(in[i]==0&&arr[i].size()!=0){//�г���û�����(����ֻ��һ���㲻��) 
			q.push(i);
			cnt[i]=1;
		}
	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		for(auto j:arr[temp]){//tempָ��j 
			if(in[j]!=0){//������� 
				cnt[j]+=cnt[temp];
				in[j]--;
			}
			if(in[j]==0)//��Ϊ��� 
				q.push(j);
		}
		if(arr[temp].size()==0)//�յ� 
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
		//out[u]++;//�б��뿪u 
		in[v]++;//�б߽���v 
	}
	solve();
	cout<<ans<<endl;
	return 0;
} 
