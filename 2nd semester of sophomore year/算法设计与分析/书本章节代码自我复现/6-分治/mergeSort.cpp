#include<bits/stdc++.h>
using namespace std;
void merge(int * arr,int *temp,int left,int mid,int right){//合并 (temp额外开辟空间)
	int l = left;//标记左半区第一个未排序的元素 
	int r = mid + 1;//标记右半区第一个未排序的元素 
	int pos = left;//临时数组元素的下标
	while(l <= mid && r <= right)
		if(arr[l] < arr[r])
			temp[pos++] = arr[l++];
		else
			temp[pos++] = arr[r++];
	while(l <= mid)//合并左半区剩余的元素 
		temp[pos++] = arr[l++];	
	while(r <= right)//合并右半区剩余的元素 
		temp[pos++] = arr[r++];	
	while(left <= right){//把临时数组中合并后的元素复制回原来的数组 
		arr[left] = temp[left];
		left++;
	}
}
void msort(int * arr,int *temp,int left,int right){//归并排序
	if(left < right){
		int mid = (left + right) / 2;
		msort(arr,temp,left,mid);
		msort(arr,temp,mid+1,right);
		merge(arr,temp,left,mid,right);
	}
}
void mergeSort(int *arr,int n){
	int temp[n];//辅助数组 
	memset(temp,0,sizeof(temp));
	msort(arr,temp,0,n - 1);
}
int main(){
	int array[] = {0,5,2,8,6,1,9,7,3};
	mergeSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
