#include <stdio.h>
#include <queue>
bool end=0;
const int maxn=1e5+100;
struct tree{
	int val;
	int dep;
	bool flag;//flag == 0 <==> # 
	tree *lson,*rson;
	tree(){
	 	flag=0;	
	}
};
std::queue <std::pair<tree*,int> > qq; 
void build(tree* &cur,int d){//结点 + 深度 
	if(end) return;
	int x=0;
	char ch;
	bool f=1;
	bool sign=1;
	int cnt=0;
	while(scanf("%c",&ch)!=EOF){
		++cnt;
		if(ch=='#'){
			f=0;
		}
		else if(ch=='-') sign=0;
		else if(ch>='0'&&ch<='9'){
			x*=10;
			x+=ch-'0';
		}
		else break;
	}
	if(sign==0) x=-x;
	if(cnt==0) {//??
		end=1;
		return;
	}
	if(f==0) {//叶子??
		cur->flag=0;
		return;
	}
	cur->flag=1;
	cur->val=x;
	cur->dep=d;
	cur->lson=new tree();
	cur->rson=new tree(); 
	qq.push({cur->lson,d+1});
	qq.push({cur->rson,d+1});
}
int ans[maxn];
void print(int tol,bool f ){
	if(f) 
		for(int i=tol;i>=1;--i)
			printf("%d ",ans[i]);	
	else 
		for(int i=1;i<=tol;++i)
			printf("%d ",ans[i]);
}
void slove(){
	tree *root=new tree();
	build(root,0);        
	while(!qq.empty()){
		build(qq.front().first,qq.front().second);//重新输入?? 
		qq.pop();
	}
	std::queue <tree*> q;
	int now=0;
	int tol=0;
	q.push(root);
	while(!q.empty()){
		tree *u=q.front();
		q.pop();
		if(u==NULL||u->flag==0) continue;
		//u是internal node 
		if(u->dep>now){
			print(tol,now%2);
			printf("\n");
			tol=0;
			now=u->dep;
		}
		ans[++tol]=u->val;
		q.push(u->lson);
		q.push(u->rson);
	}
	print(tol,now%2);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	slove();
	return 0;
}




