#include<bits/stdc++.h>
using namespace std;
string zhong,hou;
void qianxu(int l1,int r1,int l2,int r2){//l1 - r1 中序 
	if(l1>r1 || l2>r2)	return;
	else{
		char root = hou[r2];//后序最后结点为根 
		cout<<root;
		int cnt = l1; //找中序里面根的位置 
		while(zhong[cnt] != root) cnt++;
		int zuozishu = cnt - l1;
		//此时zhongxu[cnt]为根节点
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
