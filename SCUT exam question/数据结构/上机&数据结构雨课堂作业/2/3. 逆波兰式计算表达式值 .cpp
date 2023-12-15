#include<bits/stdc++.h>
#include<stack>
using namespace std;
char c;
stack<int>s;
int cnt=0;
int main()
{
	bool flag=0;
	while((c=getchar())!=EOF){
		if(c>='0'&&c<='9') {
			cnt=cnt*10+c-'0';
			flag=1;
		}
		else if(c == '+') {
			int cnt1=s.top();
			s.pop();
			int cnt2=s.top();
			s.pop();
			s.push(cnt2+cnt1);
		}
		else if(c == '-') {
			int cnt1=s.top();
			s.pop();
			int cnt2=s.top();
			s.pop();
			s.push(cnt2-cnt1);
		}else if(c == '*') {
			int cnt1=s.top();
			s.pop();
			int cnt2=s.top();
			s.pop();
			s.push(cnt2*cnt1);
		}else if(c == '/') {
			int cnt1=s.top();
			s.pop();
			int cnt2=s.top();
			s.pop();
			s.push(cnt2/cnt1);
		}
		else if(c == ' '&&flag){
			s.push(cnt);
			cnt=0;flag=0; 
		}
	}
	cout<<s.top()<<endl;
	return 0;
}
