#include<bits/stdc++.h> 
using namespace std;
#define maxn 1010
int n;
int a[maxn];
void selectSortRt(int i){
	if(i<n){//if array only has 1 elements,stop
		int k=i;
		for(int j=i+1;j<=n;j++)//find min
			if(a[j]<a[k])
				k=j;
		if(k!=i){
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
		selectSortRt(i+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	selectSortRt(1);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
