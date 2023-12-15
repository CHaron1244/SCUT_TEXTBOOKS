#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define ll long long 
#define maxn 10000010
ll n;//课程数量  也是 the size of array 
ll k;//每周翘课数量 (PS:就是要找前k个最大的,indice:(n-k)~(n-1))
ll a_sum;
ll a[maxn];
ll b[maxn];
ll ans;
int q;//the number of group
int arr[maxn];//0 - n-1  保存的是差值  最后会升序 
int a1[maxn],a2[maxn],a3[maxn];
int group[maxn/5+5][6];
int Middle[maxn/5+5];//the set of middle elements
struct fun{
	ll a;//课程
	ll b;//翘课
	ll cha;
	fun(){
		a=0;
		b=0;
		cha=0;
	}
} x[maxn]; 
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
bool cmp(fun i,fun j){
	return i.cha >= j.cha;
}
int select(int* arr,int low,int high,int k){
	int number=high-low+1;//the number of elements
	if(number<6){ //use other sort method to solve directly(if only a little elements)
		sort(arr,arr+number);
		return a[k];
	}
	q=number/5;
	for(int i=1;i<=q;i++){//find every group's middle elements
		sort(group[i],group[i]+4); //sort every group
		Middle[i] = group[i][2];
	}
	int mm=select(Middle,0,q-1,q/2);
	int len1=0,len2=0,len3=0;//divide elements into a1a2a3
	for(int i=0;i<n;i++){
		if(arr[i]<mm)
			a1[len1++] = arr[i];
		else if(a[i]==mm)
			a2[len2++] = arr[i];
		else if(a[i]>mm)
			a3[len3++] = arr[i];
	}
	if(len1 >= k)
		return select(a1,0,len1-1,k);
	if(len1+len2 >= k)
		return mm;
	if(len1+len2 < k)
		return select(a3,0,len3-1,k - len1-len2);
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		//scanf("%d",&x[i].a);
		x[i].a = read();
		a_sum+=x[i].a;
	}		
	for(int i=0;i<n;i++){
		//scanf("%d",&x[i].b);
		x[i].b = read();
	}		
	for(int i=0;i<n;i++)
		x[i].cha=x[i].b-x[i].a;
	for(int i=0;i<n;i++)
		arr[i] = x[i].cha;
	//sort(x,x+n,cmp);  //原始排序差值的方法(maybe超时) 
	for(int i=0;i<n;i++){
		int temp = i/5;
		int pos = i - temp*5;
		group[temp][pos] = a[i];
	}
//	cout<<"输出排序后的差值结果:"<<endl; 
//	for(int i=0;i<n;i++)
//		cout<<"arr["<<"i]="<<arr[i]<<" ";
//	cout<<endl; 
	int kNum = select(arr,0,n-1,k);
	//cout<<"The "<<k<<"th smallest element is "<<kNum<<endl; //k:0-n-1
	for(int i=n-1;i>=(n-k);i--)
		a_sum += arr[i];
	cout<<a_sum<<endl;
//	for(int i=0;i<n;i++)
//		cout<<"arr["<<"i]="<<arr[i]<<" ";
//	cout<<endl; 
//	for(int i=0;i<n;i++){
//		if(i<k)
//			ans+=x[i].b;
//		else
//			ans+=x[i].a;
//	} 
//	cout<<ans<<endl; 
	return 0;
}
//题意:在长度为n的a,b数组中找出一些数
//使得其和最大,并且某一边选出数的数量为k
