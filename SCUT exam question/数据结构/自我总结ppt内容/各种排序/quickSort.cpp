#include<bits/stdc++.h>
using namespace std;
void quickSort(int *array,int l,int r){
	if(l >= r)
		return ;
	int left = l,right = r;//right存储pivot的位置 
	int pivot = array[left];
	while(left < right){
		while(left < right && array[right] >= pivot)
			right--;
		if(left < right)
			array[left] = array[right];
		while(left < right && array[left] <= pivot)
			left++;
		if(left < right)
			array[right] = array[left];
		if(left >= right) //执行这个if时马上就会退出while循环 
			array[left] = pivot;
	}
	quickSort(array,l,right - 1);
	quickSort(array,right + 1,r);
}
int main(){
	int array[] = {9,6,0,1,8,5,99,7,3,2};
	quickSort(array,0,sizeof(array) / sizeof(array[0]) - 1);
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
} 
