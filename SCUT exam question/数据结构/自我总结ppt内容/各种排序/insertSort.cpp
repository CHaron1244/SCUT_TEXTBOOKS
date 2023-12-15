#include<bits/stdc++.h>
using namespace std;
void insertSort(int *a,int length){
	int i,j,temp;
	for(i = 1;i < length; i++){
		temp = a[i];
		for(j = i - 1;j>=0;j--){
			if(temp < a[j])
				a[j + 1] = a[j];
			else
				break; 
		}	
		a[j + 1] = temp;
	}
	for(i=0;i<length;i++)
		cout<<a[i]<<" ";
}
int main(){
	int array[] = {5,9,3,8,2,0,7,1,4};
	insertSort(array,sizeof(array) / sizeof(array[0])); 
	return 0;
} 
