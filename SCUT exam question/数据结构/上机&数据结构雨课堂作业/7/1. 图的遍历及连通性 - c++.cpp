#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int vertex;
int a[maxn][maxn];
int vis[maxn];
int start = 1;//Ĭ��Ϊ1 
int cnt=1;//��ͨ��֧�� 
void bfs(int s,int &count) { //�Ӷ���start��ʼ���� 
	queue<int>q;
	q.push(s);
	while(!q.empty()){ //��ɴ�s�����ܵ��ﶥ��ı�� 
		int temp = q.front(); 
		q.pop();
		if(vis[temp]==1) //����Ѿ����ʹ��� 
			continue;
		vis[temp] = 1;
		for(int j=1;j<=vertex;j++)
			if(vis[j]==0&&a[temp][j]==1)
				q.push(j);			
	}
	for(int i=1;i<=vertex;i++) { //����Ƿ񶼱���ˣ������ٴ�bfs 
		if(vis[i] == 1) //�Ѿ����ʹ� 
			continue;
		else if(vis[i] == 0) {
			count++;//��һ����ͨ��֧ 
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
