#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int arr[maxn][maxn];
int cnt[maxn];//计算出度 
int vertex;//顶点数 
int edge;//边数 
queue<int>q;
void topoSort(int arr[][maxn],int vertex) { //二维数组传参第二维度必须确定 
	for(int i = 1;i <= vertex;i++) //先放所有出度为0的顶点 
		if(cnt[i] == 0)
			q.push(i);	
	while(!q.empty()) {
		int temp = q.front();
		q.pop();
		cout<<temp<<endl;
		for(int i=1;i<=vertex;i++){
			if(arr[temp][i] == 1) {
				cnt[i]--;
				if(cnt[i] == 0)
					q.push(i);				
			}				
		}
	}
}
int main() {
	memset(arr,0,sizeof(arr));
	cin>>vertex>>edge;
	for(int i = 1 ;i <= edge; i++) {
		int u,v;
		cin>>u>>v;
		arr[u][v] = 1;
		cnt[v]++;
	}
	topoSort(arr,vertex);
	return 0;
} 
/*
测试样例： 
12  16
1 2
1 3
1 4
1 12
2 3
3 5
3 7
3 8
4 5
5 7
6 8
9 10 
9 11
9 12
10 12
11 6
*/
