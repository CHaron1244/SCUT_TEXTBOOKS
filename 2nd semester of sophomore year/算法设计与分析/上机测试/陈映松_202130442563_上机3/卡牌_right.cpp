#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1000000;
bool valid[maxn+20];
int main(){
	int n,m,t,sum=0;
	string temp;
	cin>>n>>m;
	valid[0]=true;
	for(int i=0;i<n;i++){	
		cin>>temp;
		if(temp=="10")
			t=10;
		else if(temp=="A")
			t=1;
		else if(temp=="J")
			t=11;
		else if(temp=="Q")
			t=12;
		else if(temp=="K")
			t=13;
		else 
			t=temp[0]-'0';	//Õý³£Êý×Ö 
		sum+=t;
		for(int i=m+12;i>=t;i--)
			valid[i] |= valid[i-t];	
	}
	for(int i=m;i<=m+12;i++){
		if(valid[i]){
			cout<<sum-i<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;								
}
