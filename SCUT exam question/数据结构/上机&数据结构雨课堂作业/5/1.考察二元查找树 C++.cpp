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
	if(c>='0'&&c<='9')//是数字
		number = number*10 + c - '0';
	else{//是空格 
		a[pos++] = number;
		number = 0;
	} 
}
void insert(int n,tree* &root) {
	if(root == NULL) { //指向空位置 
		root = new tree;
		root->l = root->r = NULL;                          
		root ->num = n;
		return;
	}
	else if(n < root->num)  //放左子树 
		insert(n,root->l);
	else if(n > root->num)  //放右子树 
		insert(n,root->r);	
}
void levelOrder(tree *root){
	tree *p = root;
	queue<tree*> q;
	q.push(p);
	while(!q.empty()){
		p = q.front();
		q.pop();
		cout<<p->num<<" ";//打印
		if(p->r!=NULL)
			q.push(p->r);//右孩子入队
		if(p->l!=NULL)
			q.push(p->l);//左孩子入队		
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
