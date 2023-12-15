#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int *arr,int n,int i){//数组,长度,待维护节点的下标(向下筛)--大顶堆 
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if(lson < n && arr[largest] < arr[lson])
		largest = lson;
	if(rson < n && arr[largest] < arr[rson])
		largest = rson;
	if(largest != i){
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}	
} 
void heapSort(int *arr,int n){//初始下标为0 
	int i;
	for(i = n / 2 - 1;i >= 0; i--)
		heapify(arr,n,i);
	for(i = n - 1;i > 0;i--){
		swap(&arr[i],&arr[0]);
		heapify(arr,i,0);
	}
}
int main(){
	int array[] = {0,5,2,8,6,1,9,99,7,3}; 
	heapSort(array,sizeof(array) / sizeof(array[0])); 
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
  
