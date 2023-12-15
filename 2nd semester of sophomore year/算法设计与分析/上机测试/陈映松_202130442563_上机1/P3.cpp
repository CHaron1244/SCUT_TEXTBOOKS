#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
ll N;//课程数 
ll M;//周数 
ll a[maxn];//上课 
ll b[maxn];//翘课 
ll ans[maxn];//熟练度 
ll res;//存答案 
ll ceil(ll x, ll y) {//上取整函数
	if(x%y==0) return x/y;
	else return x/y+1;
}
bool check(ll k) {//最小为k
	ll num=0;//达到k目标的上课次数 
	for(int i=1;i<=N;i++){//对于每一门课程 
		if(b[i]>a[i])//肯定不会上课 
			num+=ceil(k,b[i]); 		
		else{ 
			if(M*a[i] > k) //一直上课 
				num+=ceil(k,a[i]); 
			else{//上课加补课 
				num+=M;//先要全部上课 
				num+= ceil(k-M*a[i],b[i]);//还要补课 
			}
		}
		if(num > N*M) //不行 
			return 0;
	}
	return 1;
}
int main(){
	memset(ans,0,sizeof(ans));
	cin>>N>>M;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	ll left = 0, right = 1e18+1000;
	while (left + 1 < right) {
		ll mid = left + right >> 1;
		if (check(mid)) left = mid;//课时数够，提高要求
		else right = mid;
	}// [[[[[[ ))))) 满足课时数"[" 的最大值答案在left	
	cout << left <<endl;
	return 0;
} 
