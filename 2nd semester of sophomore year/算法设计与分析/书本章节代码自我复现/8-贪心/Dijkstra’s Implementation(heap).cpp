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
struct DijkElem {
  int vertex,distance;
  DijkElem() { vertex = -1; distance = -1; }
  DijkElem(int v, int d) { vertex = v; distance = d; }
};
bool removemin(DijkElem *H){
	
}
void insert(DijkElem temp,DijkElem * H){
	
}
void Dijkstra(int arr[][maxn] , int *D,int s) {
	int i,v,w;
	DijkElem temp;
	DijkElem E[edge];//heap
	temp.distance = 0; temp.vertex = s;
	E[0]=temp;
	DijkElem H[edge];//build the minheap
	for(i=0;i<vertex;i++){
		do{
			if(!H.removemin(temp))
				return;
		}while(vis[v] == 0)//not visited
		vis[v]=1;//set visited
		if(D[v]==bigNum)
			return;
		for(w = 1;w <= vertex;w++) 
			if(arr[v][w] != 0){ //v到w有边 
				if(D[w] > D[v] + wei[v][w]) 
					D[w] = D[v] + wei[v][w];
					temp.distance=D[w];
					temp.vertex=w;
					insert(temp,H);//insert the temp into H
			}
	}
}
//void Dijkstra(Graph* G, int* D, int s) {
//  int i, v, w;       // v is current vertex
//  DijkElem temp;
//  DijkElem E[G->e()]; // Heap array  
//  temp.distance = 0; temp.vertex = s;
//  E[0] = temp;     // Initialize heap array
//  minheap<DijkElem, DDComp> H(E, 1, G->e()); 
//  for (i=0; i<G->n(); i++) {// Get distances
//   do { if(!H.removemin(temp)) return;
//        v = temp.vertex;
//      } while (G->getMark(v) == VISITED);
//   G->setMark(v, VISITED);
//   if (D[v] == INFINITY) return;
//   for(w=G->first(v); w<G->n(); w=G->next(v,w))
//     if (D[w] > (D[v] + G->weight(v, w))) {
//       D[w] = D[v] + G->weight(v, w);
//       temp.distance = D[w]; temp.vertex = w;
//       H.insert(temp); // Insert in heap
//     }}}
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
测试样例
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
