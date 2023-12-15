#include<iostream>
using namespace std;
#define maxn 1010
int a[maxn];
int n;
const int INF = 1e8;
int max1,max2;
int f(int l,int r ,int &max1, int &max2){//return max2
    if(l==r){
        max1=a[l];
        max2=-INF;
    }
    else if(r-l==1){
        max1=max(a[l],a[r]);
        max2=min(a[l],a[r]);
    }
    else{
        int mid=(l+r)/2;
        int lmax1,lmax2,rmax1,rmax2;
        f(l,mid,lmax1,lmax2);
        f(mid+1,r,rmax1,rmax2);
        
        if(rmax1>lmax1){
            max1=rmax1;
            max2=max(lmax1,rmax2);
        }
        else{
            max1=lmax1;
            max2=max(lmax2,rmax1);    
        }
    }
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	f(0,n-1,max1,max2);
	cout<<"second is: "<<max2<<endl;
}


