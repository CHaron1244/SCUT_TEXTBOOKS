#include<bits/stdc++.h>
using namespace std;
int m;
int n;//������ 
int c;//���� 
int u,v;
int a[105][105];
int cnt[105];
int main(){
	cin>>m;//��������� 
	while(m--){
		memset(cnt,0,sizeof(cnt));
		cin>>n>>c;
		for(int j=0;j<c;j++){
			cin>>u>>v;
			a[u][v] = 1;
		}
		for(int j=1;j<=n;j++) 
			for(int i=1;i<=n;i++)
				if(a[i][j])
					cnt[j]++;
		int temp = cnt[1];
		for(int i=2;i<=n;i++)
			if(cnt[i] > temp)
				temp = cnt[i];
		cout<<temp<<endl;
	}
}
