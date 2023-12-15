#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 100010 //容量上限 
#define maxn 1010 //物品个数上限 
#define inf -1000000
int weight[maxn];
int value[maxn];
int Volumn;//最大权重数（不超过此数） 
int num;//物体数 
int dp[maxVolumn];
void DP(){
	for(int i=1;i<=num;i++)
		for(int j=weight[i];j<=Volumn;j++)//按照容量大小顺序求解
			dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);	
	cout<<dp[Volumn]<<endl;
}
int main(){
	cin>>num>>Volumn;
	for(int i=1;i<=num;i++)
		cin>>weight[i]>>value[i];
	DP();
	return 0;
} 

