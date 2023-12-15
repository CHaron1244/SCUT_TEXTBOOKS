#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1e5 + 10;
ll n;
int a[maxn];
int dp[maxn];//dp[i]=从<=i的位置可以到的最远位置 
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
//	dp[0]=a[0];
//	int temp_max=dp[0];//dp中的最大值 
//	for(int i=1;i<n;i++){ 
//		dp[i]=max(dp[i-1],a[i]+i);
//		if(dp[i]>=n-1){ //比数组还长了 
//			cout<<n-1<<endl; //max
//			return 0;
//		}
//		else //如果dp没有大于n的数,记录dp中的最大值 
//			temp_max=max(temp_max,dp[i]);		
//	}
//	cout<<temp_max<<endl;

	int right=0;//当前能跳的最长距离
	for(int i=0;i<n;i++){
		//如果当前下标小于等于更新后目前能跳的最长距离,证明还不能跳到数组的最后一个位置
		//大于的话，进入下一个循环（证明当前不可达）
		if(i <= right){
			right = max(right,i+a[i]);//更新当前能跳的最长距离
			if(right >= n-1){ //已经够了 
				cout<<n-1<<endl; //max
				return 0;
			}
		}
	}
	cout<<right<<endl;
	return 0;
}
