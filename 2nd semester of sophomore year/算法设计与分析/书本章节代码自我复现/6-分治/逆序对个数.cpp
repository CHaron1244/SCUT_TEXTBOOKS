#include<iostream>
using namespace std;
#define maxn 10010
int a[maxn],temp[maxn];
int size; 
int mergeCountInversions(int a[],int left,int mid,int right){
	int count = 0;
	int i = left, j = mid + 1;
	for (int k = left; k <= right; k++) {//归并到临时数组中
		if ((j > right) || (i <= mid) && (a[i] <= a[j]))//未越界并且不是逆序 
			temp[k] = a[i++];
		else {
			temp[k] = a[j++];
			count += mid - i + 1;		//计算逆序对数(从i到mid的数都满足条件)
		}
	}
	for (int i = left; i <= right; i++)//拷贝回数组a
		a[i] = temp[i];
	return count;
}
int countInversions_mergeSort(int a[], int left, int right)//通过归并排序计算逆序对
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		//当前数组内的逆序对数等于两个子数组的逆序对数加上归并时计算出的逆序对数
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
	for(int i=0;i<size;i++)//此时有序 
		cout<<"a["<<i<<"] = "<<a[i]<<'\t';
	return 0;
}
