#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int M = 500010;
const int INF = 0x3f3f3f3f;
int n, m;
int cnt = 0;//cnt存当前加了多少条边。
int p[N];//存储并查集(parentof) 
int result = 0;//result存的是最小生成树中所有数边的权重之和
struct Edge {
    int a, b, w;//点a和b之间存在权重为w的边
    bool operator< (const Edge &W ){//重载一下小于号,方便按权重排序
        return w < W.w;
    }
}edges[M];
int find(int x){//查找并查集的根，同时路径压缩 
    if (p[x] != x) 
		p[x] = find(p[x]);
    return p[x];
}
void kruskal() {
    sort(edges,edges + m);//第一步把所有边按权重排序
    for (int i = 1; i <= n; i ++ ) //第二步初始化并查集(vertex)
		p[i] = i;   
    for (int i = 0; i < m; i ++ ){//从小到大枚举所有边
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        //让a等于a的祖宗节点，b等于b的祖宗节点，判断a和b是否连通，就是判断a和b的祖宗节点是否相同
        a = find(a), b = find(b);
        if (a != b) {//如果两个祖宗节点不连通就把这条边加进集合
            p[a] = b;//将两个点所在的集合合并
            result += w;
            cnt++;
        }
    }   
    if (cnt < n - 1) //如果加入的边数少于n-1说明这个图不是连通的
		cout<<"Unsuccessfully!"<<endl;
	else
    	cout<<result<<endl;
    if(cnt == n-1)
    	cout<<"Successfully!"<<endl;
}
int main() {
    cin>>n>>m;//vertex , edge
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin>>a>>b>>w;//读入所有边
        edges[i] = {a, b, w};
    }
    kruskal();
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
