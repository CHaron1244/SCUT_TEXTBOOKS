#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int n;
int a[maxn];
int sum[maxn];
int f[maxn][maxn];
void DP(){
	int i,j,k,len;
	for (len = 1; len <= n; len++)
  		for (i = 1; i <= 2 * n - 1; i++) {
    		int j = len + i - 1;
    		for (k = i; k < j && k <= 2 * n - 1; k++)
      			f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
  		}
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i] = a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			sum[i] +=a[j];
		sum[n+i] = sum[i];
	}
	for(int i=1;i<=2*n;i++)
		f[i][i] = a[i];
	DP();
	int Max = f[1][n];
	for(int i=2;i<n;i++)
		if(Max <f[i][n-1+i])
			Max = f[i][n+i];
	cout<<Max<<endl; 
	return 0;
} 
