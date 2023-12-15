#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int p[N];//存储并查集(parentof) 
int result = 0;//result存的是最小生成树中所有数边的权重之和
struct Edge {
    int a, b, w;//点a和b之间存在权重为w的边
    bool operator< (const Edge &W){//重载一下小于号,方便按权重排序
        return w < W.w;
    }
} edges[M];
int find(int x){//查找并查集的根同时路径压缩 
    if (p[x] != x) 
		return p[x] = find(p[x]);
	return p[x];
}
void kruskal() {
    sort(edges,edges + m);//第一步把所有边按权重排序
    for (int i = 1; i <= n; i ++ ) //第二步初始化并查集(vertex)
		p[i] = i;   
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a);
		b = find(b);
        if (a != b) {
            p[a] = b;
            result += w;
        }
    }   
    cout<<result<<endl;
}
signed main() {
    cin>>n>>m;//vertex , edge
    for (int i = 0; i < m; i ++ ){
        int aa, bb, ww;
        cin>>aa>>bb>>ww;//读入所有边
        //edges[i] = {aa, bb, ww};
        edges[i].a = aa;
        edges[i].b = bb;
        edges[i].w = ww;
    }
    kruskal();
    return 0;
}
