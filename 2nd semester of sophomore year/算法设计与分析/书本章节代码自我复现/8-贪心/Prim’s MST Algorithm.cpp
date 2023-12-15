#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1010;
const long long INF = 0x3f3f3f3f;//����һ��INF��ʾ�����
int a[MAXN][MAXN];//�����ţ�1-n 
int dis[MAXN];//dis[]���浽����MST���ж������С����
int n,m,res;//res������ 
bool vis[MAXN];//��¼ĳ�����Ƿ���뵽����MST�С�
void prim(){
    dis[1] = 0;//�ѵ�1���뼯��S����1�ڼ���S�У����������ϵľ����ʼ��Ϊ0
    vis[1] = true;//��ʾ��1�Ѿ����뵽��S������
    for(int i = 2 ; i <= n ;i++)
		dis[i] = min(dis[i],a[1][i]);//�õ�1ȥ����dis[]
    for(int i = 2 ; i <= n ; i++){
        int temp = INF;//��ʼ������
        int t = -1;//������ȥѰ���뼯��S����ĵ���뵽�����У���t��¼�������±ꡣ
        for(int j = 2 ; j <= n; j++)
            if(vis[j]==0 && dis[j]<temp){//��������û�м��뼯��S����������㵽���ϵľ���С��temp�ͽ��±긳��t
                temp = dis[j];//���¼���V������S����Сֵ
                t = j;//�ѵ㸳��t
            }
        if(t==-1){//���t==-1����ζ���ڼ���V�Ҳ��������򼯺�S������������ʧ�ܣ���res��ֵ�������ʾ����ʧ�ܣ���������
			res = INF; 
			return;
		}
        vis[t] = true;//����ҵ�������㣬�Ͱ������뼯��S
        res+=dis[t];//��������㵽����S�ľ���
        for(int j = 2 ; j <= n ; j++)
			dis[j] = min(dis[j],a[t][j]);//���¼���ĵ����dist[]
    }
}
int main() {
	cin>>n>>m;//n-����,m-�� 
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)//��ʼ������������֮��ľ���Ϊ�������ʾ��������֮��û�бߣ�		
			a[i][j] = INF;
		dis[i] = INF;
	}
	for(int i=1;i<=m;i++) {
		int aa,b,w;
		cin>>aa>>b>>w;
		a[aa][b]=a[b][aa]=w;
	}
	prim();
	if(res==INF)//���res��ֵ���������ʾ���ܸ�ͼ����ת����һ����
		cout<<"NO"<<endl;
	else
		cout<<res<<endl;
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
