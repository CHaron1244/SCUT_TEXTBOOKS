#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int id;
	string name;
	int yuwen;
	int shuxue;
	int yingyu;
	int score;//×Ü·Ö 
	Stu(){
		score = 0;
	}
}stu[101];
bool cmp(Stu s1,Stu s2){
	return (s1.score > s2.score) ||
			(s1.score == s2.score && s1.yuwen>s2.yuwen) ||
			(s1.score == s2.score && s1.yuwen == s2.yuwen && s1.shuxue>s2.shuxue);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].name>>stu[i].yuwen>>stu[i].shuxue>>stu[i].yingyu;
		stu[i].score = (stu[i].yuwen+stu[i].shuxue+stu[i].yingyu);
	}	
	sort(stu,stu+n,cmp);
	for(int i=0;i<n;i++)
		cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
	return 0;
} 
