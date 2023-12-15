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
bool isPostOrder(int *a,int l,int r){//�ж���[l,r]�������Ƿ���� 
	if(l >= r)//����<=1������
		return true;
	if(r - l == 2) //����Ϊ3������ 
		if(a[r-1] > a[r] && a[r] > a[l])
			return true;
	//����Ǻ�����ô���һ��Ԫ�ؾ���root
	//ǰ�����ɽ�㶼����С���м����ɽ�㶼������
	int left = l;//��������ʼ 
	int right = l;//��������ʼ����ʼ����
	while(a[right] < a[r])
		right++;
	
	//��ʱ��right����������һ�����
//	cout<<"l = "<<l<<" r= "<<r<<endl;
//	cout<<"left= "<<left<<" right= "<<right<<endl;
	//Ȼ����������жϴ�right��root-1��all notes�Ƿ�ȫ����root��������false
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
