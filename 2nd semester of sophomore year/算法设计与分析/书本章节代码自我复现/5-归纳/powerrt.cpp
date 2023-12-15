#include<iostream>
using namespace std;
int Power(int x,int n){
	int y;
	if(n==0)
		y=1;
	else{
		y=Power(x,n/2);
		y=y*y;
		if(n%2)
			y*=x;
	}
	return y;
}
int main(){
	int x,n;
	cin>>x>>n;
	cout<<Power(x,n)<<endl;
	return 0;
} 
