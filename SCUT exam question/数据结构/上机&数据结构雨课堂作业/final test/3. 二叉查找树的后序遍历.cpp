#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int a[maxn];
int len=0;
void read(){
	char c;
	int num = 0;
	while((c = getchar()) !='\n') {
		if(c>='0' &&c<='9')
			num = num * 10 + c - '0';
		else if(c == ' '){
			a[len++] = num;
			num = 0;
		}		
	}
	a[len++] = num;
}
bool isPostOrder(int *a,int l,int r){//判断在[l,r]区间上是否后序 
	if(l >= r)//长度<=1的子树
		return true;
	if(r - l == 2) //长度为3的子树 
		if(a[r-1] > a[r] && a[r] > a[l])
			return true;
	//如果是后序，那么最后一个元素就是root
	//前面若干结点都比它小，中间若干结点都比他大
	int left = l;//左子树开始 
	int right = l;//右子树开始（初始化）
	while(a[right] < a[r])
		right++;
	
	//此时的right是右子树第一个结点
//	cout<<"l = "<<l<<" r= "<<r<<endl;
//	cout<<"left= "<<left<<" right= "<<right<<endl;
	//然后可以首先判断从right到root-1的all notes是否全大于root，不是则false
	int flag = 0;
	for(int i=right;i<r;i++)
		if(a[i] < a[r])
			flag++;
	if(flag > 0)
		return false; 
	return (isPostOrder(a,left,right-1) && isPostOrder(a,right,r-1));
}
int main() {
	read();
	if(isPostOrder(a,0,len-1))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
