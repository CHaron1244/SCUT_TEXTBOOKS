#include<iostream>
#include<string.h>
using namespace std;
int n,m;//n+1��m+1��
//����һ��n*m�ĸ��ӣ�Ҫ������½�(0,0)�ߵ����Ͻǣ��󷽰�����
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
