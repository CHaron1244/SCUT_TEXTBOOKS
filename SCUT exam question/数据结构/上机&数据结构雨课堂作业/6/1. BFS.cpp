#include<bits/stdc++.h>
using namespace std;
int m;
int n;//���� 
int e;//�� 
int start;//��ʼ�� 
int u,v;
int a[105][105];
int vis[105];
void showAndSign(int n){
	cout<<n<<" ";
	vis[n] = 1;//�����ѷ��� 
}
void bfs() { //�Ӷ���start��ʼ���� 
	queue<int>q;
	q.push(start);
	while(!q.empty()){
		int temp = q.front(); 
		q.pop();
		if(vis[temp]==1) //����Ѿ����ʹ��� 
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
	cin>>m;//��������� 
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
