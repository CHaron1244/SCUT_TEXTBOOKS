#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char letter[maxn][maxn];
string s1,s2;
int LCS(string s1,string s2){
	int len1=s1.length(),len2=s2.length();
	int a[len1+5][len2+5];
	for(int i=0;i<=len1;i++)
		a[i][0] = 0;
	for(int i=0;i<=len2;i++)
		a[0][i] = 0;
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1] == s2[j-1]){//match
				a[i][j] = a[i-1][j-1] + 1;
				letter[i][j]='m';//match
			}	
			else //not match
				if(a[i-1][j]>=a[i][j-1]){
					a[i][j] = a[i-1][j];
					letter[i][j] = 'u';//up
				}				
				else{
					a[i][j] = a[i][j-1];
					letter[i][j] = 'l';//left
				}					
		}
	}
	return a[len1][len2];
} 
void print_LCS(int i,int j){
	if(i==0||j==0)
		return;
	if(letter[i][j]=='m'){
		print_LCS(i-1,j-1);
		cout<<s1[i-1];
	}
	else if(letter[i][j]=='u')
		print_LCS(i-1,j);
	else
		print_LCS(i,j-1);
}
int main(){
	cin>>s1>>s2;
	int temp = LCS(s1,s2);
	cout<<"The max length is "<<temp<<endl;
	cout<<"thr LCS is: ";
	print_LCS(s1.length(),s2.length());
	return 0;
}
