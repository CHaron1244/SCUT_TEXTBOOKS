#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1100
int n;//果树的个数
int shijian;//小明的空闲时间
int h;
ll res;//果子数
ll going[maxn];//到达这棵树的时间
ll f[maxn];
ll d[maxn];
ll t[maxn];
struct Tree{
	int ff;//每个果树第一个 5 分钟能摘到果子的数量
	int dd;//以后的每5分钟摘果子数量比前一个 5分钟摘果子数量减少的数量
	int tt;//由第i个果树到第i+1个果树需要花 5*Ti分钟的路程
	Tree(){}
}tree[maxn];
ll dp[maxn][maxn];//剩余i时间，最远到达j树 
ll ceil(ll x, ll y) {//上取整函数
	if(x%y==0) return x/y;
	else return x/y+1;
}
ll fu(ll i,ll j){//剩余i时间，最远到达j树 
	if(dp[i][j])
		return dp[i][j];
	for(int k=1;k<=j;k++){//最远到达k树 
		dp[i][k] = dp[i+tree[k].tt][k-1];//没用到第k棵树(到了第k棵树但不在那里摘果子)
		int num=ceil(tree[k].ff,tree[k].dd);//最多可以摘的果子数（不然就负了） 
		for(int q=1;q<=num;q++){//q--->在第k棵树拿的果子数 
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
	going[1] = 0;//到达第1课树要0时间 
	for(int i=2;i<=n;i++)
		for(int j=2;j<=i;j++)//要到达第i课树 
			going[i]+=tree[j].tt;
	for(int i=1;i<=n;i++){//只到达第i棵树 
		ll left=shijian-going[i];//可以摘果子的时间 
		res = max(res,fu(left,i));//剩余时间，最远的树 
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
