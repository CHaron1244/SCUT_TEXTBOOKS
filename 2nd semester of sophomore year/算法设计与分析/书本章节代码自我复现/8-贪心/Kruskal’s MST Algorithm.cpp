#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int M = 500010;
const int INF = 0x3f3f3f3f;
int n, m;
int cnt = 0;//cnt�浱ǰ���˶������ߡ�
int p[N];//�洢���鼯(parentof) 
int result = 0;//result�������С���������������ߵ�Ȩ��֮��
struct Edge {
    int a, b, w;//��a��b֮�����Ȩ��Ϊw�ı�
    bool operator< (const Edge &W ){//����һ��С�ں�,���㰴Ȩ������
        return w < W.w;
    }
}edges[M];
int find(int x){//���Ҳ��鼯�ĸ���ͬʱ·��ѹ�� 
    if (p[x] != x) 
		p[x] = find(p[x]);
    return p[x];
}
void kruskal() {
    sort(edges,edges + m);//��һ�������б߰�Ȩ������
    for (int i = 1; i <= n; i ++ ) //�ڶ�����ʼ�����鼯(vertex)
		p[i] = i;   
    for (int i = 0; i < m; i ++ ){//��С����ö�����б�
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        //��a����a�����ڽڵ㣬b����b�����ڽڵ㣬�ж�a��b�Ƿ���ͨ�������ж�a��b�����ڽڵ��Ƿ���ͬ
        a = find(a), b = find(b);
        if (a != b) {//����������ڽڵ㲻��ͨ�Ͱ������߼ӽ�����
            p[a] = b;//�����������ڵļ��Ϻϲ�
            result += w;
            cnt++;
        }
    }   
    if (cnt < n - 1) //�������ı�������n-1˵�����ͼ������ͨ��
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
        cin>>a>>b>>w;//�������б�
        edges[i] = {a, b, w};
    }
    kruskal();
    return 0;
}
/*
����:
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
