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
int minVertex(int *D) {//δ�����ʵĽ����·����̵Ľ�� 
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
void Dijkstra(int arr[][maxn] , int *D,int s) {
	int i , v , w;
	for(i = 1;i <= vertex; i++) {
		v = minVertex(D);
		if(D[v] == bigNum)
			return;
		vis[v] = 1;//�����Ѿ����� 
		for(w = 1;w <= vertex;w++) 
			if(arr[v][w] != 0) //v��w�б� 
				if(D[w] > D[v] + wei[v][w]) 
					D[w] = D[v] + wei[v][w];
		cout<<"v = "<<v<<endl;	
	}
}
int main() {
	memset(arr,0,sizeof(arr));
	memset(vis,0,sizeof(vis));
	cin>>vertex>>edge;
	for(int i = 1;i <= vertex;i++)
		if(i != start)
			D[i] = bigNum;
		else
			D[i] = 0;
	for(int i=1;i <= vertex;i++)
		cout<<"D["<<i<<"] = "<<D[i]<<endl;
	cout<<"--------------------------------------"<<endl;
	for(int i = 1 ;i <= edge; i++) {
		int u,v,weight;
		cin>>u>>v>>weight;
		arr[u][v] = 1;
		wei[u][v] = weight;	
	}
	Dijkstra(arr,D,start);
	cout<<"--------------------------------------"<<endl;
	for(int i=1;i <= vertex;i++)
		cout<<"D["<<i<<"] = "<<D[i]<<endl;
	return 0;
}
/*
��������
5 6
1 2 10
1 3 3 
1 4 20
2 4 5
3 2 2
3 5 15
4 5 11 
result:0 5 3 10 18 
*/
