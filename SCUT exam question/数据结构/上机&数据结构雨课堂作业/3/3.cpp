#include<bits/stdc++.h>
using namespace std;
string zhong,hou;
void qianxu(int l1,int r1,int l2,int r2){//l1 - r1 ���� 
	if(l1>r1 || l2>r2)	return;
	else{
		char root = hou[r2];//���������Ϊ�� 
		cout<<root;
		int cnt = l1; //�������������λ�� 
		while(zhong[cnt] != root) cnt++;
		int zuozishu = cnt - l1;
		//��ʱzhongxu[cnt]Ϊ���ڵ�
		qianxu(l1,cnt-1,l2,l2+zuozishu -1);
		qianxu(cnt+1,r1,l2+zuozishu,r2-1); 
	}
}
int main()
{
	cin>>zhong>>hou;
	int l = hou.length() - 1;
	qianxu(0,l,0,l);
	return 0;
} 
