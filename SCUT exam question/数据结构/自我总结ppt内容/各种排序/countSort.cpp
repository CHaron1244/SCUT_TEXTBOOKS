#include<bits/stdc++.h>
using namespace std;
void countSort(int * arr,int len){
	if(len < 1)	
		return;
	int max = arr[0];
	for(int i =1;i < len; i++)//寻找最大元素 
		if(arr[i] > max)
			max = arr[i];
	int * count = new int[max + 1];//分配一个长度为max + 1的数组存储计数,并初始化为0
	for(int i=0;i<=max;i++)
		count[i] = 0;
	for(int i = 0; i < len; i++)//计数
		count[arr[i]]++;
	for(int i = 1;i < max + 1; i++)
		count[i] += count[i - 1];
	int *output = new int[max + 1];//创建一个临时数组保存结果
	for(int i = 0;i < len; i++){//将元素放在正确的位置上
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	} 
	for(int i = 0;i < len; i++)//将结果复制回原数组
		 arr[i] = output[i]; 
}
int main(){
	int array[] = {0,5,2,8,6,1,9,99,7,3};
	countSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
