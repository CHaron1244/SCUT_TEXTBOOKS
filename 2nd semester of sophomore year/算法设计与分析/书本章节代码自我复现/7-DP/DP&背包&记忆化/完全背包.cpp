#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 100010 //�������� 
#define maxn 1010 //��Ʒ�������� 
#define inf -1000000
int weight[maxn];
int value[maxn];
int Volumn;//���Ȩ������������������ 
int num;//������ 
int dp[maxVolumn];
void DP(){
	for(int i=1;i<=num;i++)
		for(int j=weight[i];j<=Volumn;j++)//����������С˳�����
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

