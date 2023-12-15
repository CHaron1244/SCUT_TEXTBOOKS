#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int vertex;
int a[maxn][maxn];
int vis[maxn];
int start = 1;//默认为1 
int cnt=1;//连通分支数 
void bfs(int s,int &count) { //从顶点start开始遍历 
	queue<int>q;
	q.push(s);
	while(!q.empty()){ //完成从s出发能到达顶点的标记 
		int temp = q.front(); 
		q.pop();
		if(vis[temp]==1) //结点已经访问过了 
			continue;
		vis[temp] = 1;
		for(int j=1;j<=vertex;j++)
			if(vis[j]==0&&a[temp][j]==1)
				q.push(j);			
	}
	for(int i=1;i<=vertex;i++) { //检查是否都标记了，否则再次bfs 
		if(vis[i] == 1) //已经访问过 
			continue;
		else if(vis[i] == 0) {
			count++;//下一个连通分支 
			bfs(i,count);
		}
	}
}
int main() {
	cin>>vertex;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=vertex;i++)
		for(int j=1;j<=vertex;j++)
			cin>>a[i][j];	
	bfs(start,cnt);
	cout<<cnt<<endl;
	return 0;
}
