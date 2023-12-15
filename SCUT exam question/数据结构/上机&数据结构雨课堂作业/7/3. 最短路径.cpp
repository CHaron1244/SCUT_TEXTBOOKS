#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define bigNum 1000
int arr[maxn][maxn];//存储边
int wei[maxn][maxn];//存储权重 
int vertex;//顶点数 
int edge;//边数 
int D[maxn];//存储最后结果(D[i] = 从start到i的路径长度)
int vis[maxn];
int start = 1;//起始结点,默认为1 
int endPoint; //终点 
int minVertex() {//未被访问的结点中路径最短的结点 
	int i,v;
	for(i = 1;i<=vertex;i++)
		if(vis[i] == 0) { //找到一个未访问的点 
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
		vis[v] = 1;//设置已经访问 
		for(w = 1;w <= vertex;w++) 
			if(arr[v][w] != 0) //v到w有边 
				if(D[w] > D[v] + wei[v][w]) 
					D[w] = D[v] + wei[v][w];	
	}
}
int main() {
	memset(arr,0,sizeof(arr));
	memset(vis,0,sizeof(vis));
	cin>>vertex>>edge>>start>>endPoint;
	for(int i = 1;i <= vertex;i++) //初始权重 
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
