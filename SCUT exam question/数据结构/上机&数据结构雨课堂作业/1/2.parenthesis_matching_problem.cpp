#include<bits/stdc++.h>
using namespace std;
void parenthesisMatch(string s) {
	stack<char> st;
	for(int i=0;i<s.length();i++) {
		if(s[i] == '(')
			st.push('(');
		if(s[i] == ')')
			if(st.empty()) {//匹配失败,无对应的( 
				cout<<"FALSE"<<endl;
				return;
			}
			else
				st.pop();
	}
	if(st.empty())//栈空,匹配完成 
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	return; 
}
int main()
{
	int cnt;
	cin>>cnt;
	while(cnt) {
		string s;
		cin>>s;
		parenthesisMatch(s); 
		cnt--;
	}
		
} 

