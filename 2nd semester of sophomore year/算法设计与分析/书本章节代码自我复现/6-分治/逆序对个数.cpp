#include<iostream>
using namespace std;
#define maxn 10010
int a[maxn],temp[maxn];
int size; 
int mergeCountInversions(int a[],int left,int mid,int right){
	int count = 0;
	int i = left, j = mid + 1;
	for (int k = left; k <= right; k++) {//�鲢����ʱ������
		if ((j > right) || (i <= mid) && (a[i] <= a[j]))//δԽ�粢�Ҳ������� 
			temp[k] = a[i++];
		else {
			temp[k] = a[j++];
			count += mid - i + 1;		//�����������(��i��mid��������������)
		}
	}
	for (int i = left; i <= right; i++)//����������a
		a[i] = temp[i];
	return count;
}
int countInversions_mergeSort(int a[], int left, int right)//ͨ���鲢������������
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		//��ǰ�����ڵ���������������������������������Ϲ鲢ʱ��������������
		return countInversions_mergeSort(a, left, mid) 
			 + countInversions_mergeSort(a, mid + 1, right)
			 + mergeCountInversions(a, left, mid, right);
	}
	else
		return 0;
}
int main(){
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>a[i];
	int num=countInversions_mergeSort(a,0,size-1);
	cout<<"The count inversion is: "<<num<<endl;
	for(int i=0;i<size;i++)//��ʱ���� 
		cout<<"a["<<i<<"] = "<<a[i]<<'\t';
	return 0;
}
