#include<bits/stdc++.h>
using namespace std;
int array[9] = {0,5,2,4,6,1,9,7,3};
void bubbleSort(int * arr,int len){ //���� 
	for(int i = len; i > 1;i--){ //ֻ��Ҫlen-1��exchange 
		int swapped = 0;//�ж��Ƿ�����exchange 
		for(int j = 1;j < i; j++)
			if(arr[j - 1] > arr[j]){
				swap(arr[j - 1],arr[j]);
				swapped = 1;
			}
		if(!swapped)
			break;
	}
}
int main(){
	bubbleSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
