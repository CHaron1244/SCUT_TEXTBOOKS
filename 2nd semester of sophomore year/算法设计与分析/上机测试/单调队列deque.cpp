#include<iostream>
#include<deque>
using namespace std;
#define maxn 1000100
int n, k;
int a[maxn];
deque<int> q;
void getmin(){// 得到这个队列里的最小值
	for(int i=1;i<k;i++){
		while(!q.empty() && a[q.back()]>=a[i])
			q.pop_back();
		q.push_back(i);
	}
	for(int i=k;i<=n;i++){
		while(!q.empty() && a[q.back()]>=a[i]) 
			q.pop_back();
		q.push_back(i);
		while(q.front()<=i-k)
			q.pop_front();
		printf("%d ",a[q.front()]);
	}
}
void getmax(){// 得到这个队列里的最小值
	for(int i=1;i<k;i++){
		while(!q.empty() && a[q.back()]<=a[i])
			q.pop_back();
		q.push_back(i);
	}
	for(int i=k;i<=n;i++){
		while(!q.empty() && a[q.back()]<=a[i]) 
			q.pop_back();
		q.push_back(i);
		while(q.front()<=i-k)
			q.pop_front();
		printf("%d ",a[q.front()]);
	}
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	getmin();
	q.clear();
	printf("\n");
	getmax();
	return 0;
}
/*
8 3
1 3 -1 -3 5 3 6 7

-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
