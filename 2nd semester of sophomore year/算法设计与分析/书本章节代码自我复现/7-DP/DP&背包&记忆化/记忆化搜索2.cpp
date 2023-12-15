#include<iostream>
#include<string.h>
using namespace std;
int n,m;//n+1行m+1列
//给定一个n*m的格子，要求从左下角(0,0)走到右上角，求方案数。
int f(int i,int j){
	if(i==0||j==0)
		return 1;
	if(i<0||j<0)
		return 0;
	return f(i-1,j)+f(i,j-1);	
}
int main(){
	cin>>n>>m;
	cout<<f(n,m)<<endl;
	return 0;
}
