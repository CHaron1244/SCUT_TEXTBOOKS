#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int arr[maxn][maxn];
int cnt[maxn];//������� 
int vertex;//������ 
int edge;//���� 
queue<int>q;
void topoSort(int arr[][maxn],int vertex) { //��ά���鴫�εڶ�ά�ȱ���ȷ�� 
	for(int i = 1;i <= vertex;i++) //�ȷ����г���Ϊ0�Ķ��� 
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
���������� 
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
