#include<bits/stdc++.h>
using namespace std;
struct tree{
	int num;
	int depth;
	tree* l;
	tree* r;
	tree(){
		num=depth=0;
		l=r=0;
	}
};
int ans=0;
void insert(tree* &t,int val,int d){
	if(t==NULL){
		t=new tree();
		t->depth=d;
		ans=max(t->depth,ans);
		t->num=val;
		t->l=NULL;
		t->r=NULL;
	}
	else {	
		if(t->num>val){
			insert(t->l,val,d+1);
		}
		else if(t->num<val){
			insert(t->r,val,d+1);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	char a=getchar();
	while(t--) {	
		ans=0;
		tree *root=NULL;
		char c='\0';
		int cnt=0;
		while(c!='\n') 
		{	c=getchar();			
			if(c>='0'&&c<='9')
				cnt=cnt*10+c-'0';
			else if(c == ' '){
				insert(root,cnt,1);
				cnt=0;
			}
		}
		if(cnt){
			insert(root,cnt,1);
			cnt=0;
		}
		cout<<ans;
		if(t)
			cout<<endl;
	}
	return 0;
 } 
