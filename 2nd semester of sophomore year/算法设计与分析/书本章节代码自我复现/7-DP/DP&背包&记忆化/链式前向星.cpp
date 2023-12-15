#include<bits/stdc++.h>
using namespace std;
struct edge {
  int to;//边指向的结点的编号 
  int next;//这条边的起始点的下一条边（或上一条边）的编号（每一个起始点可能有很多条边） 
} e[6005];
int head[6005];//head[i]--以i为起点的最后一条边的编号(链表的边的顺序和读入顺序正好逆序) 
int n;//节点数 
int cnt;//边数 
int f[6005][2];
int ans;
int is_h[6005];//是否有某个节点指向它（不会是root了） 
int vis[6005];
void addedge(int u, int v) {  // 建图(链式前向星) u-->v
  //每加入一条边(u, v)，就在原有的链表结构的首部插入这条边
  //因此链表的边的顺序和读入顺序正好逆序
  e[++cnt].to = v;//终点 
  e[cnt].next = head[u];//以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
  head[u] = cnt;//更新以u为起点下一条边的编号
}
void calc(int k) {
  vis[k] = 1;
  for (int i = head[k]; i!=-1; i = e[i].next) { // 枚举该结点的每个子结点
    if (vis[e[i].to]) 
		continue;
    calc(e[i].to);
    f[k][1] += f[e[i].to][0];
    f[k][0] += max(f[e[i].to][0], f[e[i].to][1]);  // 转移方程 
  }
  return;
}
void traverseFunction(){//遍历函数 
	for(int i=1;i<=n;i++)//n个点 
		for(int j=head[i];j!=-1;j=e[j].next)//遍历以i为起点的所有边 
			cout<<e[j].to<<" "<<e[j].next<<endl;
}
int main() {
  memset(head,-1,sizeof(head)); 
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) 
  	scanf("%d", &f[i][1]);
  for (int i = 1; i < n; i++) {
    int l, k;
    scanf("%d%d", &l, &k);
    is_h[l] = 1;//表示有结点指向它 
    addedge(k, l);//创建k指向l的边 
  }
//  for(int i=1;i<=n;i++)
//  	cout<<"head["<<i<<"]= "<<head[i]<<endl;
//  for(int i=1;i<n;i++)
//  	cout<<"e["<<i<<"].v = "<<e[i].to<<endl
//	  	<<"e["<<i<<"].next = "<<e[i].next<<endl;
//  for(int i=1;i<=n;i++)
//  	cout<<"is_h["<<i<<"]= "<<is_h[i]<<endl; 
  for (int i = 1; i <= n; i++)
  	if (!is_h[i]) {  // 从根结点(only one)开始DFS
      calc(i);
      printf("%d", max(f[i][1], f[i][0]));
      return 0;
    }
}
/*
对于1 2 1(weight)这条边：edge[0].to = 2;edge[0].next = -1  head[1] = 0;
对于2 3 2这条边：edge[1].to = 3;edge[1].next = -1;  head[2] = 1;
对于3 4 3这条边：edge[2].to = 4;edge[2],next = -1; head[3] = 2;
对于1 3 4这条边：edge[3].to = 3;edge[3].next = 0;   head[1] = 3;
对于4 1 5这条边：edge[4].to = 1;edge[4].next = -1; head[4] = 4;
对于1 5 6这条边：edge[5].to = 5;edge[5].next = 3;  head[1] = 5;
对于4 5 7这条边：edge[6].to = 5edge[6].next = 4;   head[4] = 6;
*/ 

