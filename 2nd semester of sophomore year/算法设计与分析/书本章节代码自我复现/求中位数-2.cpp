#include<bits/stdc++.h>
using namespace std;
int size;
void adjustHeap(int*a,int i,int j){//the size of heap is (size+1)/2
	int temp=a[i];
	for(int k=2*i+1;k<=j;k++){//k--childIndex,j--lastIndex
		if(k<j&&a[k]>a[k+1])//find the smaller child
			k++;
		if(a[k]<temp){
			a[i]=a[k];
			i=k;
		}
		else
			break;
	}
	a[i]=temp;
}
int getMid(int *a){
	int len=(size+1)/2;
	for(int i=len/2;i>=0;i--)//用前面(size+1)/2个数构成最小堆 
		adjustHeap(a,i,len-1);//heap的范围:0-len-1,大小为len 
	for(int j=len;j<size;j++){
		if(a[j]>a[0]){//元素大就加入堆 
			a[0]=a[j];
			adjustHeap(a,0,len-1);
		}
	}
	return a[0];//有(size-1)/2个数比它小 
}
int main(){
	cin>>size;
	int *a=new int[size+1];
	for(int i=0;i<size;i++)
		cin>>a[i];
	cout<<"The middle number is: "<<getMid(a)<<endl; 
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	return 0;
}
