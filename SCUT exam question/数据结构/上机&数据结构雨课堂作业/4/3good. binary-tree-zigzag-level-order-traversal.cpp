#include <stdio.h>
#include <queue>
bool end=0;
const int maxn=1e5+100;
int ans[maxn];
std::queue <int> q;
void print(int tol,bool f){
	if(f) for(int i=tol;i>=1;--i)
		printf("%d ",ans[i]);
	else for(int i=1;i<=tol;++i)
		printf("%d ",ans[i]);
	printf("\n");
}
int main(){
	int now=0;
	q.push(0);
	int tol=0;
	char ch;
	while(!q.empty()){
		int dep=q.front();
		q.pop();
		if(dep>now){//什么情况不执行? 
			print(tol,now&1);
			tol=0;
			now=dep;
		}
		int x=0;
		bool flag=1,sign=1;
		int cnt=0;
		while(scanf("%c",&ch)!=EOF){
			++cnt;
			if(ch=='#')
				flag=0;
			else if(ch=='-')
				sign=0;
			else if(ch>='0'&&ch<='9'){
				x*=10;
				x+=ch-'0';
			}
			else break;
		}
		if(cnt==0)//文件末尾 
			break;
		if(flag==0)// #
			continue;
		if(sign==0) x=-x;
		ans[++tol]=x;
		q.push(dep+1);
		q.push(dep+1);
	}
	print(tol,now&1);
	return 0;
}
