#include<iostream>
#include<cmath>
using namespace std;
int x;
int y;
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x < y)
			cout<<(y-x)<<endl;
		else if(x >= y){
			if((x-y) % 2 == 0){//diffÊÇÅ¼Êý 
				cout<<(x-y) / 2 <<endl;
			}
			else {
				int go=x+1;
				int cha=(go-y)/2;
				cout<< cha + 1<<endl;
			}
		}
	}
	return 0;
}
