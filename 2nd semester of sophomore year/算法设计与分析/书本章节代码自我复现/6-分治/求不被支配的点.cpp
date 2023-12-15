#include<iostream>
#include<algorithm>
using namespace std;
#define N 1010 
struct point{
	double x, y;
	int id;
}a[N];
bool cmp(point xx,point yy){
	return xx.x < yy.x;
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp); 
	cout<<a[n].id<<endl;
	double maxy = a[n].y;
	for (int i=n-1;i>0;i--){
		if (a[i].y>=maxy){
			printf("%d\n", a[i].id);//≤ª±ª÷ß≈‰ 
			maxy = max(maxy,a[i].y);
		}
	}
	return 0;
} 
