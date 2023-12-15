#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+100;
ll t;
struct Qujian{
	ll l;
	ll r;
}qujian[maxn];
bool cmp(Qujian q1,Qujian q2){
	return q1.r <= q2.r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
		cin>>qujian[i].l>>qujian[i].r;
	sort(qujian,qujian+t,cmp);//Sort jobs by finish time (����) 
	//for(int i=0;i<t;i++)
	//	cout<<qujian[i].l<<" "<<qujian[i].r<<endl;
	int pos = 0;//��ǰѡ�뼯�ϵ�����������
	ll cnt=1; //0�ű�ѡ��Ӧ�ã�
	for(int i=1;i<t;i++){
		if(qujian[pos].r <= qujian[i].l){ //i����Ŀ�ʼʱ������pos��������ʱ�� 
			cnt++;
			pos = i;
		}
	}
	cout<<cnt<<'\n';
	return 0;
} 
