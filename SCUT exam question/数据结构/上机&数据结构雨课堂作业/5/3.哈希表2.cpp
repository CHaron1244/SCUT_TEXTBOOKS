#include<bits/stdc++.h>
using namespace std;
int len=0;
int a[10010];
int Hash[10010];
int number=0;
int pos=0;
int i=0;
char c;
int h(int n){ //hash function
	return n%len;
}
void insert(int n,int *Hash) {
	int slot = h(n);
	for(int i=0;i<len;i++){ //最多进行len次 
		if(Hash[slot] == -1) { //空位置 
			Hash[slot] = n;
			break;
		}
		else { //有人占了 
			slot++;
			slot %= len;
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	cin>>len;
	int temp;
	for(int i=0;i<len+1;i++)
		Hash[i] = -1;
	while(cin>>temp){
		a[pos++] = temp;
	}
	a[pos] = temp;
	for(int i=0;i<pos;i++)
		insert(a[i],Hash);
	for(int i=0;i<len;i++)
		if(Hash[i] != -1) //不是空位置
			cout<<i<<" "<<Hash[i]<<endl;
	return 0;
}
