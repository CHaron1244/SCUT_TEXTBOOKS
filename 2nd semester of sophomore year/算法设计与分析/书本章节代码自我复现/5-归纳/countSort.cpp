#include<bits/stdc++.h>
using namespace std;
void countSort(int * arr,int len){
	if(len < 1)	
		return;
	int max = arr[0];
	for(int i =1;i < len; i++)//Ѱ�����Ԫ�� 
		if(arr[i] > max)
			max = arr[i];
	int * count = new int[max + 1];//����һ������Ϊmax + 1������洢����,����ʼ��Ϊ0
	for(int i=0;i<=max;i++)
		count[i] = 0;
	for(int i = 0; i < len; i++)//����
		count[arr[i]]++;
	for(int i = 1;i < max + 1; i++)
		count[i] += count[i - 1];
	int *output = new int[max + 1];//����һ����ʱ���鱣����
	for(int i = 0;i < len; i++){//��Ԫ�ط�����ȷ��λ����
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	} 
	for(int i = 0;i < len; i++)//��������ƻ�ԭ����
		 arr[i] = output[i]; 
}
int main(){
	int array[] = {0,5,2,8,6,1,9,99,7,3};
	countSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
