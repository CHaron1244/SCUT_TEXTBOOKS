#include<bits/stdc++.h>
using namespace std;
#define inf -1
#define maxn 101
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int a[maxn][maxn]; //1-n
int res[maxn][maxn];
int n;
int dfs(int preval,int x,int y){
	if(x<1||y<1||x>n||y>n)
		return 0;
	if(a[x][y] >= preval)
		return 0;
	int &val = res[x][y];
	if(val != inf)
		return val;//have found before
	val = 1;//��¼���� 
	for(int i=0;i<4;i++){
		int tx = x+dir[i][0];
		int ty = y+dir[i][1];
		val = max(val,dfs(a[x][y],tx,ty) + 1);	
	}
	return val;	
}
int main(){
	cin>>n;
	memset(res,-1,sizeof(res)); 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int cnt=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(cnt < dfs(INT_MAX,i,j))
				cnt = dfs(INT_MAX,i,j);
	cout<<cnt<<endl;
	return 0;
} 
/*����һ�� n*m�ľ���
Ҫ��ѡ��һ����㣬
Ȼ��ѡ�����������ĸ����ڷ���֮һ��ʼ����
����Ҫ��֤���ߵĵ��ֵ�ȵ�ǰ��С
����һ�������ݼ���·����Ҫ������·�����
5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
