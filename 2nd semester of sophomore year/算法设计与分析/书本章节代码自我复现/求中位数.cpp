#include<bits/stdc++.h>
using namespace std;
int len;
void swap(int*a,int m,int n){
	int temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}
int partition(int*array,int left,int right){
	if(left > right) //too small
		return -1;
    int pos = right;
    right--;
    while(left <= right){
         while(left<pos && array[left]<=array[pos]) 
		 	left++;
         while(right>left && array[right]>array[pos]) 
		 	right--;
         if(left >= right) 
		 	break;
         swap(array, left, right);
     }
     swap(array, left, pos);
     return left;
}
int median(int*a){
	if(a==NULL||len==0)
		return 0;
	int left=0;
	int right=len-1;
	int midIndex=len/2;
	int index=-1;
	while(index!=midIndex){
		index=partition(a,left,right);
		if(index < midIndex) 
			left = index + 1;
        else if(index > midIndex) 
			right = index - 1;
        else 
			break;
	}
	return a[index];
}
int main(){
	cin>>len;
	int *a=new int[len+1];
	for(int i=0;i<len;i++)
		cin>>a[i];
	int mid=median(a);
	cout<<"The middle number is: "<<mid<<endl;
	return 0;
}
/*
任意挑一个元素，以该元素为支点，将数组分成两部分，
左部分是小于等于支点的，右部分是大于支点的。
如果左部分正好是（n－1）／2个元素,那么支点的那个数就是中位数。
*/
