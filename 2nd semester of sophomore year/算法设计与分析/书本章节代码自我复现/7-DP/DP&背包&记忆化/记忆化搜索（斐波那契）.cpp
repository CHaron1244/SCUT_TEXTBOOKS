#include<bits/stdc++.h>
using namespace std;
int h[101];
long long f(int n){
	if(n<=1)
		return 1;
	int &fib = h[n];
	if(fib!=-1)
		return fib;//have found before
	fib = f(n-1) + f(n-2);
	return fib;
}
int main(){
	memset(h,-1,sizeof(h));
	int n;
	while(cin>>n)
		cout<<f(n)<<endl;
	return 0;
} 
