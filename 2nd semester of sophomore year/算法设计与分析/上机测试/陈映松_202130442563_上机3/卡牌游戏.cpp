#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 1000010
ll N; //��Χ:1-1e6
ll M; //��Χ:1-1e6 	1<=N*M<=1e8
ll dp[maxn];
ll Sum(ll * arr){
	ll ans=0;
	for(int i=0;i<N;i++)
		ans+=dp[i];
	return ans;
}
bool check(ll * arr,ll len,ll n){ //�ж��Ƿ����ҳ�ĳЩ���Ƶĵ�����ǡ��Ϊn 
	if(n==0) 
		return false;
	else if(len==1)//���鳤��Ϊ1
		return arr[0] == n;
	for(int i=0;i<len;i++)
		if(arr[i]==n||check(arr+i+1,len-i-1,n-arr[i])) //i�������֮�Ϳ��Թ���n-arr[i] 
			return true;
	return false; 
}
bool check2(ll * arr,ll i,ll s){ //�ж��Ƿ����ҳ�ĳЩ���Ƶĵ�����ǡ��Ϊs
	if(s==0) 
		return true;
	else if(i==1)//���鳤��Ϊ1 
		return arr[0]==s;//�����0���պõ���s �򷵻�true
	else if(arr[i]>s)//�±�Ϊi a[i]�Ѿ�����s,�϶�����ѡ 
		return check2(arr,i-1,s);
	else//�ж�ѡ�벻ѡa[i] ѡa[i]||��ѡcheck2
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
			dp[i]=temp-'0';	//�������� 
	}
	//cout<<"�����ܺ�Ϊ:"<<Sum(dp)<<endl;
	if(Sum(dp) < M){
		//cout<<"�޷�����о�!"<<endl;
		cout<<-1<<endl;
	}
	else
		for(ll i = M;i<=Sum(dp);i++)
			if(check2(dp,N,i)){
				//cout<<i<<"�ǿ��Եģ�"<<endl; 
				cout<<Sum(dp) - i<<endl;
				break;
			}	
	return 0;								
}
