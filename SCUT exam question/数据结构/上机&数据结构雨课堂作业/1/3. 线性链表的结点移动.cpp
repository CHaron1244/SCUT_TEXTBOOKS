#include <bits/stdc++.h>
#define link ListNode
using namespace std;
struct ListNode { 
	int w; 
	ListNode* nxt; 
	ListNode(){
		nxt=NULL;
	}
};
link *last=NULL;//最大值的前一个指针 
link *maxx=NULL;//最大值指针 
void insert(link * &head,link * &tail,int x){
	link *cur=new link();
	cur->nxt=NULL;
	cur->w=x; 
	if(maxx==NULL||x>maxx->w){ 
		maxx=cur;
		last=tail;
	}
	if(head==NULL)
		head=cur;	
	if(tail==NULL)
		tail=cur;	
	else {
		tail->nxt=cur;
		tail=cur;
	}
}
void print(link *head){
	while(head!=NULL){
		printf("%d ",head->w);
		head=head->nxt;
	}
	printf("\n");
}
void del(link* &head){
	if(last==NULL)//?? 
		head=maxx->nxt;
	else 
		last->nxt=maxx->nxt;
}
int main(){
	link *head=NULL;link* tail=NULL;
	int x;
	while(cin >> x)
		insert(head,tail,x);
	insert(head,tail,maxx->w);
	del(head);
	print(head);
	return 0;
}
