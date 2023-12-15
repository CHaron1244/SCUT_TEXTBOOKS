#include<bits/stdc++.h>
using namespace std;
#define maxVolumn 10010
#define maxn 1010
int weight[maxn];
int value[maxn];
int W;//背包体积（不超过此数） 
int num;//物体数 
int f[maxVolumn];
int main() {
	cin>>num>>W;
	for(int i=1;i<=num;i++)
		cin>>weight[i]>>value[i];
	for (int i = 1; i <= num; i++)
  		for (int l = W; l >= weight[i]; l--) //按照容量大小逆序求解(如果是正序的话，同一个物品可能会多次使用) 
		  f[l] = max(f[l], f[l - weight[i]] + value[i]);
	cout<<f[W]<<endl;//背包容量为W时最大的价值为f[W] 
}
