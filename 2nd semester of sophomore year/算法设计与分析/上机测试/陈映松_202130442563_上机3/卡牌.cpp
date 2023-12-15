#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 1000050
ll N; //范围:1-1e6
ll M; //范围:1-1e6 	1<=N*M<=1e8
ll a[maxn];
ll dp[2][maxn];//dp[i][s]表示从0到i能否构建成和为s的真假值
ll temp_max;
void check2(ll s){
	for(int j=0;j<=s;j++)
		dp[0][j]=0; 
	if(a[0]<=s)//当第0个已经比s要大 则显然无法来构建s 只能是小于s的时候
		dp[0][a[0]]=1; 	 
	for(int i=0;i<2;i++)
		dp[i][0]=1;//当dp[i][j] 即要给定的值为0时 表示无需其他值来构建了 目前已完成则就是true了  	
	for(int i=1;i<N;i++) {
		for(int j=1;j<=s;j++)
			if(a[i]>j)
				dp[i%2][j]=dp[(i-1)%2][j];
			else if(a[i]<=j){
				int t3= dp[(i-1)%2][j-a[i]];
				int t4=dp[(i-1)%2][j];
				dp[i%2][j]=(t3||t4);
			}	
	}		
}
int main(){
	cin>>N>>M;
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=0;i<N;i++){
		string temp;
		cin>>temp;
		if(temp=="10")
			a[i]=10;
		else if(temp=="A")
			a[i]=1;
		else if(temp=="J")
			a[i]=11;
		else if(temp=="Q")
			a[i]=12;
		else if(temp=="K")
			a[i]=13;
		else 
			a[i]=temp[0]-'0';	//正常数字 
		temp_max+=a[i];
	}
	if(temp_max<M){
		cout<<-1<<'\n';
		return 0;
	}
	check2(M+12); 
	for(ll i = M;i<=M+12;i++)
		if(dp[(N-1)%2][i]){//从0到N-1可以组成i 
			//cout<<i<<"是可以的！"<<endl; 
			cout<<temp_max - i<<'\n';
			break;
		}
	return 0;								
}
