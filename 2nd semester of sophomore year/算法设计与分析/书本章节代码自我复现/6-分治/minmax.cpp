#include<iostream>
#include<cmath>
using namespace std;
void minmax(int *a,int low,int high,int &Min,int &Max){
	if(high<low)
		return;
	else if(low==high)
		Min=Max=a[low];
	else if(high-low==1){
		Min = min(a[low],a[high]);
		Max = max(a[low],a[high]);
	}
	else{
		int mid=(low+high)/2;
		int temp_min,temp_max;
		minmax(a,low,mid,temp_min,temp_max);
		minmax(a,mid+1,high,Min,Max);
		Max = max(temp_max,Max);
        Min = min(temp_min,Min);
	}
}
int main(){
	int n,Min,Max;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	minmax(a,0,n-1,Min,Max);
	cout<<"Min = "<<Min<<endl;
	cout<<"Max = "<<Max<<endl;
	return 0;
}
