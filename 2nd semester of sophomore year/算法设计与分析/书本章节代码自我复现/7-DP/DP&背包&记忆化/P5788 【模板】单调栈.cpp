#include<iostream>
#include<stack>
using namespace std;
#define maxn 3000010
int a[maxn];
int f[maxn];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	stack<int>s;
	for(int i=n;i>=1;i--){
		while(!s.empty()&&a[s.top()]<=a[i]) 
			s.pop();//弹出栈顶比当前数小的
		//存储答案,由于没有比她大的要输出0,所以加了个三目运算
		f[i]=s.empty()?0:s.top();
		//cout<<"f["<<i<<"]= "<<f[i]<<endl;
		s.push(i);//压入当前元素
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	return 0;
}
