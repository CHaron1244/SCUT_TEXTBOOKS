#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
ll N;//�γ��� 
ll M;//���� 
ll a[maxn];//�Ͽ� 
ll b[maxn];//�̿� 
ll ans[maxn];//������ 
ll res;//��� 
ll ceil(ll x, ll y) {//��ȡ������
	if(x%y==0) return x/y;
	else return x/y+1;
}
bool check(ll k) {//��СΪk
	ll num=0;//�ﵽkĿ����Ͽδ��� 
	for(int i=1;i<=N;i++){//����ÿһ�ſγ� 
		if(b[i]>a[i])//�϶������Ͽ� 
			num+=ceil(k,b[i]); 		
		else{ 
			if(M*a[i] > k) //һֱ�Ͽ� 
				num+=ceil(k,a[i]); 
			else{//�ϿμӲ��� 
				num+=M;//��Ҫȫ���Ͽ� 
				num+= ceil(k-M*a[i],b[i]);//��Ҫ���� 
			}
		}
		if(num > N*M) //���� 
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
		if (check(mid)) left = mid;//��ʱ���������Ҫ��
		else right = mid;
	}// [[[[[[ ))))) �����ʱ��"[" �����ֵ����left	
	cout << left <<endl;
	return 0;
} 
