#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define bigNum 1000
int arr[maxn][maxn];//�洢��
int wei[maxn][maxn];//�洢Ȩ�� 
int vertex;//������ 
int edge;//���� 
int D[maxn];//�洢�����(D[i] = ��start��i��·������)
int vis[maxn];
int start = 1;//��ʼ���,Ĭ��Ϊ1 
int endPoint; //�յ� 
int minVertex() {//δ�����ʵĽ����·����̵Ľ�� 
	int i,v;
	for(i = 1;i<=vertex;i++)
		if(vis[i] == 0) { //�ҵ�һ��δ���ʵĵ� 
			v = i;
			break; 
		}
	for(i++;i<=vertex;i++)
		if(vis[i] == 0 && D[i] < D[v])
			v = i;
	return v;
}
void Dijkstra() {
	int i , v , w;
	for(i = 1;i <= vertex; i++) {
		v = minVertex();
		if(D[v] == bigNum)
			return;
		vis[v] = 1;//�����Ѿ����� 
		for(w = 1;w <= vertex;w++) 
			if(arr[v][w] != 0) //v��w�б� 
				if(D[w] > D[v] + wei[v][w]) 
					D[w] = D[v] + wei[v][w];	
	}
}
int main() {
	memset(arr,0,sizeof(arr));
	memset(vis,0,sizeof(vis));
	cin>>vertex>>edge>>start>>endPoint;
	for(int i = 1;i <= vertex;i++) //��ʼȨ�� 
		if(i != start)
			D[i] = bigNum;
		else
			D[i] = 0;
	for(int i = 1 ;i <= edge; i++) {
		int u,v,weight;
		cin>>u>>v>>weight;
		if(arr[u][v] == 0) {
			arr[u][v] = 1;
			wei[u][v] = weight;
		}
		else if(arr[u][v] == 1 && wei[u][v] > weight)
			wei[u][v] = weight;
	}
	Dijkstra();
	cout<<D[endPoint]<<endl;
	return 0;
}
