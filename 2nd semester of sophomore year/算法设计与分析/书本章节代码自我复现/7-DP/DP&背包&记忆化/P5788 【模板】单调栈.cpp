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
			s.pop();//����ջ���ȵ�ǰ��С��
		//�洢��,����û�б������Ҫ���0,���Լ��˸���Ŀ����
		f[i]=s.empty()?0:s.top();
		//cout<<"f["<<i<<"]= "<<f[i]<<endl;
		s.push(i);//ѹ�뵱ǰԪ��
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	return 0;
}
