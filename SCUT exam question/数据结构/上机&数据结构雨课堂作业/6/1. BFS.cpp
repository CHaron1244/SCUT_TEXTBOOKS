#include<bits/stdc++.h>
using namespace std;
int m;
int n;//顶点 
int e;//边 
int start;//起始点 
int u,v;
int a[105][105];
int vis[105];
void showAndSign(int n){
	cout<<n<<" ";
	vis[n] = 1;//设置已访问 
}
void bfs() { //从顶点start开始遍历 
	queue<int>q;
	q.push(start);
	while(!q.empty()){
		int temp = q.front(); 
		q.pop();
		if(vis[temp]==1) //结点已经访问过了 
			continue;
		showAndSign(temp); 
		for(int j=0;j<n;j++){
			if(vis[j]==1)
				continue;
			else if(a[temp][j]==1)
				q.push(j);
		}			
	}
	cout<<endl;
}
int main(){
	cin>>m;//测试情况数 
	while(m--){
		memset(vis,0,sizeof(vis));
		cin>>n>>e>>start;
		for(int j=0;j<e;j++){
			cin>>u>>v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		bfs();
	}
}
