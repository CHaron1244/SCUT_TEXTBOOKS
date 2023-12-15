#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int a[maxn];
int num;//the number to be found
int bs(int *a,int low,int high,int x){ //return the index
 	if(low>high)
 		return 0;
 	else{
 		int mid = (low+high)/2;	
 		if(x == a[mid])
 			return mid;
 		else if(x < a[mid])
 			return bs(a,low,mid-1,x);
 		else
 			return bs(a,mid+1,high,x);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>num;
	int index = bs(a,0,n-1,num);
	if(index != 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
