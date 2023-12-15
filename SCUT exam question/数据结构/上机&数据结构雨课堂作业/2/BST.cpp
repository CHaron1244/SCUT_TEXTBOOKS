#include <bits/stdc++.h>
using namespace std;
struct node{
	int w;
	int dep;
	node *l, *r;
};
node *root;
int ans=0;
void insert(node * &cur,int val,int d){
	if(cur==NULL){
		cur=new node();
		cur->dep=d;
		ans=max(cur->dep,ans);
		cur->w=val;
		cur->l=NULL;
		cur->r=NULL;
	}
	else {
		//cout << val << " " << cur->w << endl;
		if(cur->w>val){
			insert(cur->l,val,d+1);
		}
		else if(cur->w<=val){
			insert(cur->r,val,d+1);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	char ch;
	while(scanf("%c",&ch),ch!='\n');
	while(T--){
		ans=0;
		root=NULL;
		bool f=1;
		int num=0;
		while(scanf("%c",&ch),ch!='\n'){
			if(ch>='0'&&ch<='9'){
				num=num*10+ch-'0';
			} 
			else if(ch=='-'){
				f=0;
			}
			else{
				if(!f) num=-num;
				insert(root,num,1);
				//if(root!=NULL) cout << root->w;
				num=0;
				f=1;
			}
		}
		if(num){
			if(!f) num=-num;
			insert(root,num,1);
			num=0;
			f=1;
		}
		printf("%d",ans);
		if(T) printf("\n");
	}
	return 0;
} 
