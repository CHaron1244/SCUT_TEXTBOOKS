#include<bits/stdc++.h>
using namespace std;
void shellSort(int * arr,int len){//ϣ������(��С��������) 
	int i,j,inc,key;//inc ���� 
	for(inc = len / 2; inc > 0; inc /=2){//��ʼ����: len/2 , ÿһ��֮�����2
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
