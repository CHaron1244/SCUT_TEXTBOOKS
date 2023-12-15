#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int a[maxn];
int cnt;
int n;
int candidate(int m){
	int j=m;
	int c=a[m];
	cnt=1;
	while(j<n&&cnt>0){
		j++;
		if(a[j]==c)
			cnt++;
		else
			cnt--;
	}
	if(j==n)
		return c;
	else	
		return candidate(j+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int c=candidate(1);
	cnt=0;
	for(int j=1;j<=n;j++)
		if(a[j]==c)
			cnt++;
	if(cnt>n/2)
		cout<<c<<endl;
	else
		cout<<0<<endl;
	return 0;
}
