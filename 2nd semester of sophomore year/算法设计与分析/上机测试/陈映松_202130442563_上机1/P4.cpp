#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1100
int n;//�����ĸ���
int shijian;//С���Ŀ���ʱ��
int h;
ll res;//������
ll going[maxn];//�����������ʱ��
ll f[maxn];
ll d[maxn];
ll t[maxn];
struct Tree{
	int ff;//ÿ��������һ�� 5 ������ժ�����ӵ�����
	int dd;//�Ժ��ÿ5����ժ����������ǰһ�� 5����ժ�����������ٵ�����
	int tt;//�ɵ�i����������i+1��������Ҫ�� 5*Ti���ӵ�·��
	Tree(){}
}tree[maxn];
ll dp[maxn][maxn];//ʣ��iʱ�䣬��Զ����j�� 
ll ceil(ll x, ll y) {//��ȡ������
	if(x%y==0) return x/y;
	else return x/y+1;
}
ll fu(ll i,ll j){//ʣ��iʱ�䣬��Զ����j�� 
	if(dp[i][j])
		return dp[i][j];
	for(int k=1;k<=j;k++){//��Զ����k�� 
		dp[i][k] = dp[i+tree[k].tt][k-1];//û�õ���k����(���˵�k��������������ժ����)
		int num=ceil(tree[k].ff,tree[k].dd);//������ժ�Ĺ���������Ȼ�͸��ˣ� 
		for(int q=1;q<=num;q++){//q--->�ڵ�k�����õĹ����� 
			//dp[i][k] = max(dp[i][k] , (q*tree[k].ff - (q-1)*q*tree[k].dd/2 + dp[i-q][k]));
			dp[i][k] = max(dp[i][k] , (q*tree[k].ff - (q-1)*q*tree[k].dd/2 + dp[i-tree[i].tt-q][k]));
		}			
	}
	return dp[i][j];
}
int main(){
	cin>>n>>h;
	shijian=h*12;
	for(int i=1;i<=n;i++)  cin>>tree[i].ff;
	for(int i=1;i<=n;i++)  cin>>tree[i].dd;
	for(int i=2;i<=n;i++) cin>>tree[i].tt;
	tree[1].tt=0;
	going[1] = 0;//�����1����Ҫ0ʱ�� 
	for(int i=2;i<=n;i++)
		for(int j=2;j<=i;j++)//Ҫ�����i���� 
			going[i]+=tree[j].tt;
	for(int i=1;i<=n;i++){//ֻ�����i���� 
		ll left=shijian-going[i];//����ժ���ӵ�ʱ�� 
		res = max(res,fu(left,i));//ʣ��ʱ�䣬��Զ���� 
	}
	for(int i=1;i<=n;i++)
		res=max(res,dp[i][h]);
	cout<<res<<endl;
	return 0;
} 
/*
3
1
4 5 6
1 2 1
1 2
*/



#include <iostream>
#include <algorithm>
using namespace std;
int n, h;
int a[110], b[110], c[110];
int a1[110];
int main() {
    int k, m;
    long long sum = 0, max = 0;
    int i, j, h1;
    cin >> n >> h;
    h *= 12;
    h1 = h;

    for (i = 1; i <= n; i++) {
        cin >> a[i];
        a1[i] = a[i];
    }

    for (i = 1; i <= n; i++) {
        cin >> b[i];
    }

    c[1] = 0;

    for (i = 2; i <= n; i++) {
        cin >> k;
        c[i] = c[i - 1] + k;
    }

    for (i = 1; i <= n; i++) {
        h = h - c[i];
        sum = 0;
        long long Max = 1;

        while (h > 0) {
            for (j = 1; j <= i; j++) {
                if (a[Max] < a[j])
                    Max = j;
            }

            if (a[Max] == 0)
                break;

            sum += a[Max];
            a[Max] -= b[Max];

            if (a[Max] < 0) {
                a[Max] = 0;
            }

            h--;

        }

        if (max < sum)
            max = sum;

        h = h1;

        for (j = 1; j <= n; j++) {
            a[j] = a1[j];
        }
    }

    cout << max;
    return 0;
}
