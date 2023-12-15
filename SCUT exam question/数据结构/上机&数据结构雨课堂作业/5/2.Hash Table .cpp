#include<bits/stdc++.h>
using namespace std;
int t;
int m;//the number of words in the given passage
int n;//the number of queries
string s[1010];
int cnt[1010];
int main(){
	cin>>t;
	while(t--){
		cin>>m>>n;
		string find[n+1];
		for(int i=1;i<=m;i++)//¾ä×Ó 
			cin>>s[i];
		for(int i=1;i<=n;i++)//´ý²éÕÒµ¥´Ê 
			cin>>find[i];
		for(int i=1;i<=n;i++)
			cnt[i] = 0;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(find[i] == s[j])
					cnt[i]++;
		}	
		for(int i=1;i<=n;i++)
			cout<<cnt[i]<<" ";
		cout<<endl;
	}
	return 0;
}
