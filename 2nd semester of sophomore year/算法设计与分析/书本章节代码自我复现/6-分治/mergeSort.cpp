#include<bits/stdc++.h>
using namespace std;
void merge(int * arr,int *temp,int left,int mid,int right){//�ϲ� (temp���⿪�ٿռ�)
	int l = left;//����������һ��δ�����Ԫ�� 
	int r = mid + 1;//����Ұ�����һ��δ�����Ԫ�� 
	int pos = left;//��ʱ����Ԫ�ص��±�
	while(l <= mid && r <= right)
		if(arr[l] < arr[r])
			temp[pos++] = arr[l++];
		else
			temp[pos++] = arr[r++];
	while(l <= mid)//�ϲ������ʣ���Ԫ�� 
		temp[pos++] = arr[l++];	
	while(r <= right)//�ϲ��Ұ���ʣ���Ԫ�� 
		temp[pos++] = arr[r++];	
	while(left <= right){//����ʱ�����кϲ����Ԫ�ظ��ƻ�ԭ�������� 
		arr[left] = temp[left];
		left++;
	}
}
void msort(int * arr,int *temp,int left,int right){//�鲢����
	if(left < right){
		int mid = (left + right) / 2;
		msort(arr,temp,left,mid);
		msort(arr,temp,mid+1,right);
		merge(arr,temp,left,mid,right);
	}
}
void mergeSort(int *arr,int n){
	int temp[n];//�������� 
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
