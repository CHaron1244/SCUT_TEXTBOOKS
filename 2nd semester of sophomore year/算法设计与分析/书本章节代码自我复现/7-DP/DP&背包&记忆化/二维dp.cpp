#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int a[maxn],b[maxn];
int dp[maxn][maxn];
int n,m,t;
void DP(){
	for(int k=1;k<=n;k++) 
		for(int i=m;i>=a[k];i--)
			for(int j=t;j>=b[k];j--)
				dp[i][j] = max(dp[i][j],dp[i-a[k]][j-b[k]]+1);		
}
int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	DP();	
	cout<<dp[m][t]<<endl;
}
/*
3:59 7:15 29
2 29 14
5 68 0
12 5 6
5 60 13
8 82 9
7 11 2
7 84 8
7 56 6
10 54 3
10 38 1
9 24 8
10 9 13
5 30 1
11 15 3
10 57 7
3 13 10
5 4 9
9 13 7
2 34 9
6 63 11
7 68 9
10 60 9
12 22 5
3 39 3
1 21 13
9 24 8
7 61 12
9 72 7
3 33 10

2841
*/
