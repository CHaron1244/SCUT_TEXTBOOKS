#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 100010 //�������� 
#define maxn 1010 //��Ʒ�������� 
#define inf -1000000
int weight[maxn];//1-n
int value[maxn];
int W;//��������������������� 
int num;//������ 
int dp[maxn][maxVolumn];//dp[i][j]��ʾѡȡǰi�����壬����Ϊjʱ������ֵ 
int dp2[2][maxVolumn];//�������飬��ʡ�ռ� 
int max(int a,int b){
	return a>b?a:b;
}
void DP(){//normal edition
	dp[0][0] = 0;//��ʼ��
	for (int i = 1; i <= num; i++)
  		for (int j = 0; j <= W; j++) 
			if(j >= weight[i]) //ʣ��ռ���Կ���װ��װ��i������ 
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i]);
			else //������ѡ��i������ 
				dp[i][j] = dp[i-1][j];
	cout<<dp[num][W]<<endl;
} 
void DP2(){//��������汾 
	dp2[0][0] = 0;
	int pre = 0;
	int maxCapacity = 0;
	for(int i=0;i<num;i++) {
		maxCapacity += weight[i];
		for(int k=0;k<=maxCapacity;k++)
			dp2[pre^1][k] = inf;
			for(int j=0;j<=W;j++)
				if(j >= weight[i])
					dp2[pre^1][j] = max(dp2[pre][j], dp2[pre][j-weight[i]] + value[i]);
				else
					dp2[pre^1][j] = dp2[pre][j];
		pre ^= 1;
	}
	cout<<max(dp[0][W], dp[1][W])<<endl;
}
int main() {
	cin>>num>>W;
	for(int i=1;i<=num;i++)
		cin>>weight[i]>>value[i];	 
	//DP();
	DP2();
}
