#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 10010
#define maxn 1010
int weight[maxn];
int value[maxn];
int W;//��������������������� 
int num;//������ 
int f[maxVolumn];
int main() {
	cin>>num>>W;
	for(int i=1;i<=num;i++)
		cin>>weight[i]>>value[i];
	for (int i = 1; i <= num; i++)
  		for (int l = W; l >= weight[i]; l--) //����������С�������(���������Ļ���ͬһ����Ʒ���ܻ���ʹ��) 
		  f[l] = max(f[l], f[l - weight[i]] + value[i]);
	cout<<f[W]<<endl;//��������ΪWʱ���ļ�ֵΪf[W] 
}
