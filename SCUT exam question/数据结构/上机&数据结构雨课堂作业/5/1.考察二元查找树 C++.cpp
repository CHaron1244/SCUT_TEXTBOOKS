#include<bits/stdc++.h>
using namespace std;
struct tree{
	int num;
	tree* l;
	tree* r;
	tree(){
		l = r = NULL;
	}
};
int a[10010];
int number=0;
int pos=0;
char c;
void read(){
	if(c>='0'&&c<='9')//������
		number = number*10 + c - '0';
	else{//�ǿո� 
		a[pos++] = number;
		number = 0;
	} 
}
void insert(int n,tree* &root) {
	if(root == NULL) { //ָ���λ�� 
		root = new tree;
		root->l = root->r = NULL;                          
		root ->num = n;
		return;
	}
	else if(n < root->num)  //�������� 
		insert(n,root->l);
	else if(n > root->num)  //�������� 
		insert(n,root->r);	
}
void levelOrder(tree *root){
	tree *p = root;
	queue<tree*> q;
	q.push(p);
	while(!q.empty()){
		p = q.front();
		q.pop();
		cout<<p->num<<" ";//��ӡ
		if(p->r!=NULL)
			q.push(p->r);//�Һ������
		if(p->l!=NULL)
			q.push(p->l);//�������		
	}
}
int main() {
	int temp;
	while(cin>>temp)
		a[pos++] = temp;
	a[pos] = temp;
	tree * root = NULL;
	for(int i=0;i<pos;i++)
		insert(a[i],root);
	levelOrder(root);
	return 0;
} 
