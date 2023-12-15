#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int a[maxn];
int num,slot,k;
int main() {
	int t;
	cin>>t;
	while(t--){
		int cnt=0;
		cin>>num>>slot>>k;
		for(int i=0;i<num;i++){
			cin>>a[i];
			if(a[i] % slot == k)
				cnt++;
		}		
		cout<<cnt<<endl;
	}
	return 0;
}
