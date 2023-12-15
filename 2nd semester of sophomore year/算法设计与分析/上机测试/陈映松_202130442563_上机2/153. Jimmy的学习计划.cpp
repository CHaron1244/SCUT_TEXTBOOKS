#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+1;
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		res*=10;
		res+=ch-'0';
		ch=getchar();
	}
	return res;
}
ll a[maxn];
int n,m;
ll ans=0;

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans+=a[i];
	}
	for(int i=1,x;i<=n;++i){
		x=read();
		a[i]-=x;
	}
	nth_element(a+1,a+m,a+n+1);
	for(int i=1;i<=m;++i){
		ans-=a[i];
	}
	printf("%lld",ans);
	
	
	return 0;
}
