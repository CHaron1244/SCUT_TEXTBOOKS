#include<bits/stdc++.h>
using namespace std;
int m;
int n;//���� 
int e;//�� 
int start;//��ʼ�� 
int u,v;
int a[105][105];
int vis[105];
void dfs(int p) { //�Ӷ���start��ʼ����
	vis[p] = 1;//����ѷ���
	cout<<p<<" ";
	for(int i=0;i<n;i++) 
		if(a[p][i]==1 && vis[i]==0) 
			dfs(i);
}
int main(){
	cin>>m;//��������� 
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
