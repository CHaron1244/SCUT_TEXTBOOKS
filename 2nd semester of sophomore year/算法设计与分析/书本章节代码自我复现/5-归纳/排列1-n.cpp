#include<iostream>
using namespace std;
#define maxn 1010
int a[maxn];
int n;
void exchange(int m,int n){
	int temp = a[m];
	a[m] = a[n];
	a[n]=temp;
}
void perm(int m){
	if(m==n){
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else{
		for(int j=m;j<=n;j++){
			exchange(j,m);
			perm(m+1);
			exchange(j,m);	
		}
	}
		
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i] = i;
	perm(1);
	return 0;
} 
