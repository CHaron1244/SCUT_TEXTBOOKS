#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int n;
int heap[maxn];
int sz; 
int getmin(int cur,int size){//return min child
	int a=1e9,b=1e9,l=2*cur,r=2+cur+1;
	if(l>size&&r>size) return -1;//no child
	if(l<=size) a=heap[l];
	if(r<=size) b=heap[r];
	if(a<b)return l;
	return r;	
}
void siftdown(int cur,int size){
	int nxt=getmin(cur,size);
	while(nxt!=-1&&heap[cur]>heap[nxt]){
		swap(heap[cur],heap[nxt]);
		cur=nxt;
	}
}
void build(){
	for(int i=(sz>>1);i>=1;--i)// 1 - n
		siftdown(i,sz);
}
int ans=0;
void insert(int x){
	heap[++sz]=x;
	int cur=sz;
	while((cur/2)&&heap[cur]<heap[cur/2]) {
		swap(heap[cur],heap[cur/2]);
		cur/=2;
	}
}
void work(){
	int a,b;
	while(sz>=2){
		a=heap[1];
		swap(heap[1],heap[sz]);
		sz--;
		siftdown(1,sz);
		b=heap[1];
		swap(heap[1],heap[sz]);
		sz--;
		siftdown(1,sz);
		ans+=(a+b);//??
		insert(a+b);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&heap[i]);
	sz=n;//size 
	build();
	work();
	printf("%d",ans);
	return 0;
}
