#include<bits/stdc++.h>
using namespace std;
char a[10010];
int cnt=0;
int cnt2=0;
struct tree{
	char c;
	tree*l;
	tree*r;	
};
tree *root;
void buildtree(char *a,int len){
	for(int i=1;i<=len;i++){
		if(root==NULL){
		root->c = a[cnt2++];
		root->l=root->r=NULL;
		}
		if(a[cnt2++]=='#')
			continue;
		buildtree(a,len);
	}
}
void printtree(tree*root){
	int inverse=1;
	if(root==NULL)
		return;
	cout<<root<<endl;
	if(inverse==1){
		printtree(root->r);
		printtree(root->l);
	}
	else if(inverse==-1){	
		printtree(root->l);
		printtree(root->r);
	}
	inverse*=-1;
}
int main(){
	char c;
	while((c=getchar())!='\n'){
		if(c==' ')
			continue;
		a[++cnt] = c;
	}
	buildtree(a,cnt);
	printtree(root);
	return 0;
}
