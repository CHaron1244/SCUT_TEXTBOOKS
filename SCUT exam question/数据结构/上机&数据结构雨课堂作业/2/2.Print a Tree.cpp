#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+100;
char s[maxn];
int now=1;
struct tree{
	char c;
	tree* l;
	tree* r;
	tree(){
		c='\0';
		l=r=NULL;
	}
};
void insert(tree* &root){
	root = new tree();
	root->c = s[now];
	root->l = NULL;
	root->r = NULL;
	if(s[now]>='A'&&s[now]<='Z'){
		++now;
		return;
	}
	++now;
	insert(root->l);
	insert(root->r); 
}
void levelTraversal(tree* root){
	queue<tree*>q;
	q.push(root);
	while(!q.empty()) {
		tree*node=q.front();
		q.pop();
		cout<<node->c;
		if(node->l!=NULL)
			q.push(node->l);
		if(node->r!=NULL)
			q.push(node->r);
	}	
}
int main()
{
	int t;
	cin>>t;
	while(t--) {
		tree*root = NULL;
		cin>>s;
		now=0;
		insert(root);  
		levelTraversal(root);
		if(t) cout<<endl;
	}
	return 0;
}
