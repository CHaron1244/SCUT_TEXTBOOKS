#include<bits/stdc++.h>
using namespace std;
void selectSort(int * array,int len){
	int i,j,min;
	for(i = 0;i<len;i++){
		min = i;
		for(j = i + 1;j < len; j++)
			if(array[j] < array[min])
				min = j;
		swap(array[min],array[i]);
	}
}
int main(){
	int array[] = {0,5,2,8,6,1,9,99,7,3};
	selectSort(array,sizeof(array) / sizeof(array[0]));
	for(int i=0;i<sizeof(array) / sizeof(array[0]);i++)
		cout<<array[i]<<" ";
	return 0;
}
