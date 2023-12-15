#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int arr[maxn][maxn];
int edge[maxn][maxn];
int out[maxn];//入度 
int cnt[maxn];//计算出度 
int vertex;//顶点数 
queue<int>q;
void topoSort(int arr[][maxn],int vertex) { //二维数组传参第二维度必须确定 		
	for(int i = 0;i < vertex;i++) //先放所有出度为0的顶点 
		if(cnt[i] == 0)
			q.push(i);	
	cout<<"[";
	while(!q.empty()) {
		int temp = q.front();
		q.pop();
			cout<<" "<<temp;
		for(int j=1;j<=out[temp];j++){
			int i = edge[temp][j];
			if(arr[temp][i] == 1) {
				cnt[i]--;
				if(cnt[i] == 0)
					q.push(i);				
			}
		}
	}
	cout<<"]"<<endl;
}
int main() {
	memset(arr,0,sizeof(arr));
	memset(edge,0,sizeof(edge));//存储边的插入顺序 
	cin>>vertex;
	if(vertex == 0) 
		return 0;
	else {
	for(int i = 0 ;i < vertex; i++) { //每个顶点 
		int count = 1;
		char c1;
		int flag=0;
		int begin;
		c1 = getchar(); //读掉第一个 [ 
		while((c1=getchar()) != ']') {
			if(c1 >='0' && c1 <='9' && flag == 0) { //第一个数字（起点） 
				begin = (c1 - '0');
				flag = 1; 
			}
			else if(c1 >='0' && c1 <='9' && flag == 1) { //读到数字 
				int temp = c1 - '0';
				arr[begin][temp] = 1;
				edge[begin][count++] = temp;//从begin出发的第count条边到达temp 
				out[begin]++;//出度 
				cnt[temp]++;//入度 
			}
		}
		if(i!=vertex-1){
			c1 = getchar();
			c1 = getchar(); //读掉两个换行符 
		}			
	}
	topoSort(arr,vertex);	
	}
	
	return 0;
} 
