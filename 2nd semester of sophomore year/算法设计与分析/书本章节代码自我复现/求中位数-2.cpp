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
	for(int i=len/2;i>=0;i--)//��ǰ��(size+1)/2����������С�� 
		adjustHeap(a,i,len-1);//heap�ķ�Χ:0-len-1,��СΪlen 
	for(int j=len;j<size;j++){
		if(a[j]>a[0]){//Ԫ�ش�ͼ���� 
			a[0]=a[j];
			adjustHeap(a,0,len-1);
		}
	}
	return a[0];//��(size-1)/2��������С 
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
