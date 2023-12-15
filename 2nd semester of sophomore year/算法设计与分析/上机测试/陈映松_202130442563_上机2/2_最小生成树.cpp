#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int M = 5e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int p[N];//�洢���鼯(parentof) 
int result = 0;//result�������С���������������ߵ�Ȩ��֮��
struct Edge {
    int a, b, w;//��a��b֮�����Ȩ��Ϊw�ı�
    bool operator< (const Edge &W){//����һ��С�ں�,���㰴Ȩ������
        return w < W.w;
    }
} edges[M];
int find(int x){//���Ҳ��鼯�ĸ�ͬʱ·��ѹ�� 
    if (p[x] != x) 
		return p[x] = find(p[x]);
	return p[x];
}
void kruskal() {
    sort(edges,edges + m);//��һ�������б߰�Ȩ������
    for (int i = 1; i <= n; i ++ ) //�ڶ�����ʼ�����鼯(vertex)
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
        cin>>aa>>bb>>ww;//�������б�
        //edges[i] = {aa, bb, ww};
        edges[i].a = aa;
        edges[i].b = bb;
        edges[i].w = ww;
    }
    kruskal();
    return 0;
}
