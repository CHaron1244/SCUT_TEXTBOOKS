#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int k;//find the Kth smallest element
int q;//the number of group
int n;//the size of array
int a[maxn];//0 - n-1
int a1[maxn],a2[maxn],a3[maxn];//make sure all elements > 0
int group[maxn/5+5][6];//0 - q-1 ; 0-4
int Middle[maxn/5+5];//the set of middle elements
int select(int *a,int low,int high,int k){
	int number=high-low+1;//the number of elements
	if(number<16){ //use other sort method to solve directly(if only a little elements)
		sort(a,a+number);
		return a[k];
	}
	q=number/5;
	for(int i=1;i<=q;i++){//find every group's middle elements
		sort(group[i],group[i]+4); //sort every group
		Middle[i] = group[i][2];
	}
	int mm=select(Middle,0,q-1,q/2);
	int len1=0,len2=0,len3=0;//divide elements into a1a2a3
	for(int i=0;i<n;i++){
		if(a[i]<mm)
			a1[len1++] = a[i];
		else if(a[i]==mm)
			a2[len2++] = a[i];
		else if(a[i]>mm)
			a3[len3++] = a[i];
	}
	if(len1 >= k)
		return select(a1,0,len1-1,k);
	if(len1+len2 >= k)
		return mm;
	if(len1+len2 < k)
		return select(a3,0,len3-1,k - len1-len2);
}
int main(){
	cout<<"input k: ";//find the Kth smallest element
	cin>>k;
	cout<<"input n: ";//the size of array
	cin>>n;
	cout<<"input the array: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		int temp = i/5;
		int pos = i - temp*5;
		group[temp][pos] = a[i];
	}
	int kNum = select(a,0,n-1,k);
	cout<<"The "<<k<<"th smallest element is "<<kNum<<endl; //k:0-n-1
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";//ÉýÐò 
	return 0;
}
/*example:
13 25
8 33 17 51 57 49 35 11 25 37 14 3 2 13 52 12 6 29 32 54 5 16 22 23 7
*/
