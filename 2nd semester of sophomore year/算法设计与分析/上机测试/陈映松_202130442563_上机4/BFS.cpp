#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define ll long long
#define inf 0x3f3f
#define pll pair<ll,ll>
ll fx[8]={2,1,-1,-2,-2,-1,1,2};//��Ϊx 
ll fy[8]={-1,-2,-2,-1,1,2,2,1};//��Ϊy 
const ll maxn = 410;
struct point{
	int x;
	int y;
	int step;
	point(){
		x=0;
		y=0;
		step=inf;//��ʼ��ÿ���㶼�޷����� 
	}
	point(int x1,int y1,int step1){
		x=x1;
		y=y1;
		step=step1;
	}
} p;
int vis[maxn][maxn];
ll n;
ll L;//���̴�С  4<=L<=300
ll x1,x2,y1,y2;
ll Min(ll a,ll b){
	if(a<=b)
		return a;
	return b;
}
void solve(){
	ll L;//���̴�С  4<=L<=300
	ll x1,x2,y1,y2;
	scanf("%lld",&L);
	scanf("%lld",&x1);
	scanf("%lld",&y1);
	scanf("%lld",&x2);
	scanf("%lld",&y2);
	queue<point> q;
	memset(vis,0,sizeof(vis));
	point p ;
	p.x = x1;
	p.y = y1;
	p.step = 0;
	q.push(p);
	if(x1==x2&&y1==y2){//��ʼ����յ���ͬ
		cout<<0<<endl;
		return;
	} 
	vis[x1][y1]=1;
	while(!q.empty()){
		point temp=q.front();
		q.pop();
		if(temp.x==x2&&temp.y==y2){
			cout<<temp.step<<endl;
			return;
		}
		for(int i=0;i<8;i++){//��ʼ�����ĺ�̵�Ž�
			ll temp_x=temp.x+fx[i];
			ll temp_y=temp.y+fy[i];
			if(temp_x>=0&&temp_x<=L-1&&temp_y>=0&&temp_y<=L-1&&vis[temp_x][temp_y]==0){//����Ե�������㲢�������֮ǰδ������ 
				point p_temp;
				p_temp.x=temp_x;
				p_temp.y=temp_y;
				p_temp.step = temp.step+1;
				q.push(p_temp);
				vis[temp_x][temp_y]=1;
			}
		}
	}
}	
int main(){
	scanf("%lld",&n);
	while(n--)
		solve();
	return 0;
} 
