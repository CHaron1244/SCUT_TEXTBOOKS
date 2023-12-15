#include<bits/stdc++.h> 
using namespace std;
#define maxn 1010
int n;
int a[maxn];
void insertrt(int i){
	if(i>1){
		int x=a[i];
		insertrt(i-1);
		int j=i-1;
		while(j>0&&a[j]>x){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	insertrt(n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
