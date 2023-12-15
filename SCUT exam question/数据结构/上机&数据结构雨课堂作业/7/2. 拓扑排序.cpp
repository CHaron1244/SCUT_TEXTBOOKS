#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int arr[maxn][maxn];
int edge[maxn][maxn];
int out[maxn];//��� 
int cnt[maxn];//������� 
int vertex;//������ 
queue<int>q;
void topoSort(int arr[][maxn],int vertex) { //��ά���鴫�εڶ�ά�ȱ���ȷ�� 		
	for(int i = 0;i < vertex;i++) //�ȷ����г���Ϊ0�Ķ��� 
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
	memset(edge,0,sizeof(edge));//�洢�ߵĲ���˳�� 
	cin>>vertex;
	if(vertex == 0) 
		return 0;
	else {
	for(int i = 0 ;i < vertex; i++) { //ÿ������ 
		int count = 1;
		char c1;
		int flag=0;
		int begin;
		c1 = getchar(); //������һ�� [ 
		while((c1=getchar()) != ']') {
			if(c1 >='0' && c1 <='9' && flag == 0) { //��һ�����֣���㣩 
				begin = (c1 - '0');
				flag = 1; 
			}
			else if(c1 >='0' && c1 <='9' && flag == 1) { //�������� 
				int temp = c1 - '0';
				arr[begin][temp] = 1;
				edge[begin][count++] = temp;//��begin�����ĵ�count���ߵ���temp 
				out[begin]++;//���� 
				cnt[temp]++;//��� 
			}
		}
		if(i!=vertex-1){
			c1 = getchar();
			c1 = getchar(); //�����������з� 
		}			
	}
	topoSort(arr,vertex);	
	}
	
	return 0;
} 
