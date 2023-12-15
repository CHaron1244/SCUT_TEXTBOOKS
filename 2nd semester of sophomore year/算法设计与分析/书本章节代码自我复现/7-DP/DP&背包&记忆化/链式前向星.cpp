#include<bits/stdc++.h>
using namespace std;
struct edge {
  int to;//��ָ��Ľ��ı�� 
  int next;//�����ߵ���ʼ�����һ���ߣ�����һ���ߣ��ı�ţ�ÿһ����ʼ������кܶ����ߣ� 
} e[6005];
int head[6005];//head[i]--��iΪ�������һ���ߵı��(����ıߵ�˳��Ͷ���˳����������) 
int n;//�ڵ��� 
int cnt;//���� 
int f[6005][2];
int ans;
int is_h[6005];//�Ƿ���ĳ���ڵ�ָ������������root�ˣ� 
int vis[6005];
void addedge(int u, int v) {  // ��ͼ(��ʽǰ����) u-->v
  //ÿ����һ����(u, v)������ԭ�е�����ṹ���ײ�����������
  //�������ıߵ�˳��Ͷ���˳����������
  e[++cnt].to = v;//�յ� 
  e[cnt].next = head[u];//��uΪ�����һ���ߵı�ţ�Ҳ����������������ͬ����һ���ߵı��
  head[u] = cnt;//������uΪ�����һ���ߵı��
}
void calc(int k) {
  vis[k] = 1;
  for (int i = head[k]; i!=-1; i = e[i].next) { // ö�ٸý���ÿ���ӽ��
    if (vis[e[i].to]) 
		continue;
    calc(e[i].to);
    f[k][1] += f[e[i].to][0];
    f[k][0] += max(f[e[i].to][0], f[e[i].to][1]);  // ת�Ʒ��� 
  }
  return;
}
void traverseFunction(){//�������� 
	for(int i=1;i<=n;i++)//n���� 
		for(int j=head[i];j!=-1;j=e[j].next)//������iΪ�������б� 
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
    is_h[l] = 1;//��ʾ�н��ָ���� 
    addedge(k, l);//����kָ��l�ı� 
  }
//  for(int i=1;i<=n;i++)
//  	cout<<"head["<<i<<"]= "<<head[i]<<endl;
//  for(int i=1;i<n;i++)
//  	cout<<"e["<<i<<"].v = "<<e[i].to<<endl
//	  	<<"e["<<i<<"].next = "<<e[i].next<<endl;
//  for(int i=1;i<=n;i++)
//  	cout<<"is_h["<<i<<"]= "<<is_h[i]<<endl; 
  for (int i = 1; i <= n; i++)
  	if (!is_h[i]) {  // �Ӹ����(only one)��ʼDFS
      calc(i);
      printf("%d", max(f[i][1], f[i][0]));
      return 0;
    }
}
/*
����1 2 1(weight)�����ߣ�edge[0].to = 2;edge[0].next = -1  head[1] = 0;
����2 3 2�����ߣ�edge[1].to = 3;edge[1].next = -1;  head[2] = 1;
����3 4 3�����ߣ�edge[2].to = 4;edge[2],next = -1; head[3] = 2;
����1 3 4�����ߣ�edge[3].to = 3;edge[3].next = 0;   head[1] = 3;
����4 1 5�����ߣ�edge[4].to = 1;edge[4].next = -1; head[4] = 4;
����1 5 6�����ߣ�edge[5].to = 5;edge[5].next = 3;  head[1] = 5;
����4 5 7�����ߣ�edge[6].to = 5edge[6].next = 4;   head[4] = 6;
*/ 

