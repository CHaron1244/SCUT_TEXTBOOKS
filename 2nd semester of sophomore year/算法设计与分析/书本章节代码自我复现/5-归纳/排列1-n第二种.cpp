#include<iostream>
using namespace std;
#define maxn 1010
int a[maxn];
int n;
void per(int m){
	if(m==0){
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else{
		for(int j=1;j<=n;j++){
			if(a[j]==0){
				a[j]=m;
				per(m-1);
				a[j]=0;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=0;
	per(n);
	return 0;
}
