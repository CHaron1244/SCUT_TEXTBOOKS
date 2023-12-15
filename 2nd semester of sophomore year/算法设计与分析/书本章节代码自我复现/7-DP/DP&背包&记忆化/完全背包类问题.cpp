#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 100010 //容量上限 
#define maxn 1010 //物品个数上限 
#define Mod 100000007
int value[maxn];
int Volumn;//最大权重数（不超过此数） 
int n;//货币数目 
int dp[maxn][maxVolumn];
void DP(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=Volumn;j++)
			dp[i][j] = (dp[i-1][j] + dp[i][j-value[i]]) % Mod; 
	}
	cout<<dp[n][Volumn]<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>value[i];
	dp[0][0] = 0;
	DP();
	return 0;
}
