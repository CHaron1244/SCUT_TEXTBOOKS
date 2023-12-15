#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1010;
const long long INF = 0x3f3f3f3f;//定义一个INF表示无穷大。
int a[MAXN][MAXN];//顶点编号：1-n 
int dis[MAXN];//dis[]储存到集合MST所有顶点的最小距离
int n,m,res;//res保存结果 
bool vis[MAXN];//记录某个点是否加入到集合MST中。
void prim(){
    dis[1] = 0;//把点1加入集合S，点1在集合S中，将它到集合的距离初始化为0
    vis[1] = true;//表示点1已经加入到了S集合中
    for(int i = 2 ; i <= n ;i++)
		dis[i] = min(dis[i],a[1][i]);//用点1去更新dis[]
    for(int i = 2 ; i <= n ; i++){
        int temp = INF;//初始化距离
        int t = -1;//接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标。
        for(int j = 2 ; j <= n; j++)
            if(vis[j]==0 && dis[j]<temp){//如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
                temp = dis[j];//更新集合V到集合S的最小值
                t = j;//把点赋给t
            }
        if(t==-1){//如果t==-1，意味着在集合V找不到边连向集合S，生成树构建失败，将res赋值正无穷表示构建失败，结束函数
			res = INF; 
			return;
		}
        vis[t] = true;//如果找到了这个点，就把它加入集合S
        res+=dis[t];//加上这个点到集合S的距离
        for(int j = 2 ; j <= n ; j++)
			dis[j] = min(dis[j],a[t][j]);//用新加入的点更新dist[]
    }
}
int main() {
	cin>>n>>m;//n-顶点,m-边 
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)//初始化任意两个点之间的距离为正无穷（表示这两个点之间没有边）		
			a[i][j] = INF;
		dis[i] = INF;
	}
	for(int i=1;i<=m;i++) {
		int aa,b,w;
		cin>>aa>>b>>w;
		a[aa][b]=a[b][aa]=w;
	}
	prim();
	if(res==INF)//如果res的值是正无穷，表示不能该图不能转化成一棵树
		cout<<"NO"<<endl;
	else
		cout<<res<<endl;
	return 0;
}
/*
样例:
6 8
1 3 7
1 5 9
2 3 5
2 6 6
3 4 1
3 6 2
4 6 2
5 6 1 
*/
