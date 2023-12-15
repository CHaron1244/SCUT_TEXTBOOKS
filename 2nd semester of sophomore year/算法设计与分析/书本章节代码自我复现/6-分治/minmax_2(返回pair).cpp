#include<bits/stdc++.h>
using namespace std;
struct S
{
	int max;
	int min;
};
S MAXMIN(int i,int j,int b[]){
	S s,SL,SR;
	int mid;
	if(i==j) //the size of array is 1
	{
		s.max=s.min=b[i];
		return s;
	}
	if(i==j-1) //the size of array is 2
	{
		if(b[i]>=b[j])
		{
			s.max=b[i];
			s.min=b[j];
			return s;
		}
		if(b[i]<b[j])
		{
			s.max=b[j];
			s.min=b[i];
			return s;
		}
	}
	mid=(i+j)/2;
	SL=MAXMIN(i,mid,b);
	SR=MAXMIN(mid+1,j,b);
	if(SL.max>SR.max)
		s.max=SL.max;
	else
		s.max=SR.max;
	if(SL.min>SR.min)
		s.min=SR.min;
	else
		s.min=SL.min;
	return s;
}
int main(){
	int n,a[100];
	S d;
	scanf("%d",&n);
	for(int k=0;k<=n-1;k++)
		cin>>a[k];
	d=MAXMIN(0,n-1,a);
	printf("最大值为:%d,最小值为:%d\n",d.max,d.min);
	return 0;
}
