#include<bits/stdc++.h>
using namespace std;
void shellSort(int * arr,int len){//希尔排序(缩小增量排序) 
	int i,j,inc,key;//inc 增量 
	for(inc = len / 2; inc > 0; inc /=2){//初始增量: len/2 , 每一趟之后除以2
		for(i = inc; i < len; i++){
			key = arr[i];
			for(j = i; j >= inc && key < arr[j - inc]; j -= inc)
				arr[j] = arr[j - inc];
			arr[j] = key;
		}
	} 
}
int main(){
	int array[9] = {0,5,2,8,6,1,9,7,3};
	shellSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
} 
