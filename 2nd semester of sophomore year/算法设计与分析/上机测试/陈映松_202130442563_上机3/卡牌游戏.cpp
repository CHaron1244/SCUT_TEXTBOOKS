#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 1000010
ll N; //范围:1-1e6
ll M; //范围:1-1e6 	1<=N*M<=1e8
ll dp[maxn];
ll Sum(ll * arr){
	ll ans=0;
	for(int i=0;i<N;i++)
		ans+=dp[i];
	return ans;
}
bool check(ll * arr,ll len,ll n){ //判断是否能找出某些卡牌的点数和恰好为n 
	if(n==0) 
		return false;
	else if(len==1)//数组长度为1
		return arr[0] == n;
	for(int i=0;i<len;i++)
		if(arr[i]==n||check(arr+i+1,len-i-1,n-arr[i])) //i后面的数之和可以构成n-arr[i] 
			return true;
	return false; 
}
bool check2(ll * arr,ll i,ll s){ //判断是否能找出某些卡牌的点数和恰好为s
	if(s==0) 
		return true;
	else if(i==1)//数组长度为1 
		return arr[0]==s;//如果第0个刚好等于s 则返回true
	else if(arr[i]>s)//下标为i a[i]已经大于s,肯定不会选 
		return check2(arr,i-1,s);
	else//判断选与不选a[i] 选a[i]||不选check2
		return check2(arr,i-1,s-arr[i])||check2(arr,i-1,s); 
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		char temp;
		cin>>temp;
		if(temp=='A')
			dp[i]=1;
		else if(temp=='J')
			dp[i]=11;
		else if(temp=='Q')
			dp[i]=12;
		else if(temp=='K')
			dp[i]=13;
		else 
			dp[i]=temp-'0';	//正常数字 
	}
	//cout<<"数组总和为:"<<Sum(dp)<<endl;
	if(Sum(dp) < M){
		//cout<<"无法消灭敌军!"<<endl;
		cout<<-1<<endl;
	}
	else
		for(ll i = M;i<=Sum(dp);i++)
			if(check2(dp,N,i)){
				//cout<<i<<"是可以的！"<<endl; 
				cout<<Sum(dp) - i<<endl;
				break;
			}	
	return 0;								
}
