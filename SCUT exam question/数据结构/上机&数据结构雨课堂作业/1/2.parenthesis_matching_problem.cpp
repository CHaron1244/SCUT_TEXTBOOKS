#include<bits/stdc++.h>
using namespace std;
void parenthesisMatch(string s) {
	stack<char> st;
	for(int i=0;i<s.length();i++) {
		if(s[i] == '(')
			st.push('(');
		if(s[i] == ')')
			if(st.empty()) {//ƥ��ʧ��,�޶�Ӧ��( 
				cout<<"FALSE"<<endl;
				return;
			}
			else
				st.pop();
	}
	if(st.empty())//ջ��,ƥ����� 
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

