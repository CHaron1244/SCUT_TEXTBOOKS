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
������һ��Ԫ�أ��Ը�Ԫ��Ϊ֧�㣬������ֳ������֣�
�󲿷���С�ڵ���֧��ģ��Ҳ����Ǵ���֧��ġ�
����󲿷������ǣ�n��1����2��Ԫ��,��ô֧����Ǹ���������λ����
*/
