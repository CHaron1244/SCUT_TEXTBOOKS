#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 100010 //�������� 
#define maxn 1010 //��Ʒ�������� 
#define Mod 100000007
int value[maxn];
int Volumn;//���Ȩ������������������ 
int n;//������Ŀ 
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
