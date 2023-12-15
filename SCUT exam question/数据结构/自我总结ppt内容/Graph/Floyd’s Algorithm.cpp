#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int dis[maxn][maxn]; //顶点编号:0 ~ vertex-1 
int vertex;
int edge;
void floyd(int dis[][maxn],int vertex,int edge) {
	for (int k=0; k<vertex; k++)
    	for (int i=0; i<vertex; i++)
    		for (int j=0; j<vertex; j++)
    			if (dis[i][j] > (dis[i][k] + dis[k][j]))
    				dis[i][j] = dis[i][k] + dis[k][j];
}
void showResult(int dis[][maxn],int vertex) {
	for(int i=0;i<vertex;i++) {
		for(int j=0;j<vertex;j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}			
} 
int main() {
	cin>>vertex>>edge;//输入顶点数，边数
	for(int i=0;i<vertex;i++) 
		for(int j=0;j<vertex;j++)
			cin>>dis[i][j];
	floyd(dis,vertex,edge);
	showResult(dis,vertex);
	return 0;
}
/*
样例： 
6 9
0 10 10000 20 10000 2
10 0 3 5 10000 10000
10000 3 0 10000 15 10000
20 5 10000 0 11 10
10000 10000 15 11 0 3
2 10000 10000 10 3 0
*/
