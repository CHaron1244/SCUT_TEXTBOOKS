//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define maxn 1000010
//bool flag=0;
//ll n;//ͼƬ����(��10�ı���) 
//ll m;//�ļ������� 
//ll a[maxn];
//ll ans;//��Ҫ����ճ���ļ���������Сֵ 
////ll dp[maxn][maxn*maxn];
//void check(ll m,ll num){//���鳤��,�� 
//	if(a[m]==num)
//		flag=true;
//	else if(m==1)
//		return;
//	else{
//		check(m-1,num-a[m]);
//		check(m-1,num);
//	}
//	
//}
//int main(){
//	cin>>n>>m;
//	for(int i=0;i<m;i++)
//		scanf("%lld",&a[i]);
//	ll train=n*0.7;
//	ll test=n*0.3;
//	check(m,test);
//	if(flag==1){//����һЩ���ĺ�Ϊtest 
//		cout<<0<<endl;
//		return 0;
//	}
//	else{
//		ll temp=0;
//		for(int i=test-1;i>=1;i--){
//			flag=0;
//			check(m,i);
//			if(flag==1){
//				temp=i;
//				break;
//			}
//		}
//	}
//	return 0;
//} 
//idea:sort+cumsum
//������ɾ���test������� 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1000010;
ll N;//ͼƬ����(��10�ı���) 
ll M;//�ļ������� 
ll a[maxn];
ll ans;//��Ҫ����ճ���ļ���������Сֵ 
bool valid[maxn+20];
int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	int n=M;//n--���鳤��
	int m=N*0.3;//test_number  m---�� 
	int t;
	valid[0]=true;
	for(int i=0;i<n;i++){	
		cin>>t;
		for(int i=m+12;i>=t;i--)
			valid[i] |= valid[i-t];	
	}
	for(int i=0;i<=m;i++){
		if(valid[m-i] || valid[m + i]){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;								
}



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
const int _ = 1000005;
int p[_], c[_], a[_], b[_], v[_], f[_];
int N, M, cnt, t;
int main() {
	N = read(), M = read();
	for (int i = 1; i < M; ++i) {
		p[i] = read();
		c[p[i]]++;
	}
	int t = read();
	p[M] = t;
	c[p[M]]++;	
	for (int i = 1; i < _; ++i) {
		if (c[i]) {//i���λ������ 
			a[++t] = i;
			b[t] = c[i];
		}
	}
	N = (N / 10) * 3;
	for (int i = 1; i <= t; ++i) {
		int k = 1;
		while (k <= b[i]) {
			v[++cnt] = k * a[i];
			b[i] -= k;
			k <<= 1;
		}
		if (b[i] > 0) {
			v[++cnt] = b[i] * a[i];
		}
	}
	f[0] = 1;
	for (int i = 1; i <= cnt; ++i) {
		for (int j = N + a[t]; j >= v[i]; --j) {
			f[j] |= f[j - v[i]];
		}
	}
	for (int i = 0; i <= a[t]; ++i) {
		if ((N + i < _ && f[N + i]) || (N - i >= 0 && f[N - i])) {
			printf("%d\n", i);
			return 0;
		}
	}
}
