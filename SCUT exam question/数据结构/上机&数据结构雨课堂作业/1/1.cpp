#include<bits/stdc++.h>
using namespace std;
struct ListNode { 
	int val;
	ListNode* next; 
};
int main()
{
	int l1,l2;
	while(cin>>l1>>l2) {
		int l=l1+l2;
		int a[l];
		for(int i =0;i<l;i++)	
			cin>>a[i];
		sort(a,a+l);
		for(int i =0;i<l;i++)	
			cout<<a[i]<<" ";
		cout<<endl;	
	}
}



