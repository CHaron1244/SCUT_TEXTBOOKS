#include<bits/stdc++.h>
using namespace std;
int m;
int n;//顶点 
int e;//边 
int start;//起始点 
int u,v;
int a[105][105];
int vis[105];
void dfs(int p) { //从顶点start开始遍历
	vis[p] = 1;//标记已访问
	cout<<p<<" ";
	for(int i=0;i<n;i++) 
		if(a[p][i]==1 && vis[i]==0) 
			dfs(i);
}
int main(){
	cin>>m;//测试情况数 
	for(int i=0;i<m;i++){
		memset(vis,0,sizeof(vis));
		cin>>n>>e>>start;
		for(int j=0;j<e;j++){
			cin>>u>>v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		dfs(start);
		cout<<endl;
	}
}
