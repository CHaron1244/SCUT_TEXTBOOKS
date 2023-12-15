#include<iostream>
using namespace std;
struct tree{
	int num;
	tree *l, *r;
	tree(){
		num=0;
		l=r=NULL;
	}
};
void insert(tree* &t,int val){
	if(t==NULL){
		t=new tree();
		t->num=val;
	}
	else {	
		if(t->num>val)
			insert(t->l,val);
		else if(t->num<val)
			insert(t->r,val);
	}
}
int h(tree* root){
	if(root==NULL)
		return 0;
	return 1+max(h(root->l),h(root->r));
}
int main()
{
	int t;
	cin>>t;
	char a=getchar();//¶ÁÈë»»ÐÐ 
	while(t--) {	
		tree *root=NULL;
		char c='\0';
		int cnt=0;
		while(c!='\n') 
		{	
			c=getchar();			
			if(c>='0'&&c<='9')
				cnt=cnt*10+c-'0';
			else if(c == ' '){
				insert(root,cnt);
				cnt=0;
			}
		}
		if(cnt){
			insert(root,cnt);
			cnt=0;
		}
		cout<<h(root);
		if(t)
			cout<<endl;
	}
	return 0;
}
