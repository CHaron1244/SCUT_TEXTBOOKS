#include<bits/stdc++.h>
using namespace std;
int n,len;
int han(int x){//�������ֵ�ĺ��� 
	int res=0,last;
	while(x&&x%10==0)x/=10;
	last=x%10;
	while(x){
		res+=2;
		x/=10;
	}
	if(last==5)res--;
	return res;
}
int find(int l,int r){
	int ans,minn=0x3f3f3f3f;
	if(r-l<=len){ //ö�� 
		for(int i=l;i<=r;i++){
			int x=han(i);
			if(x<minn)minn=x,ans=i;
		}
	}
	else {
		int i=l,j=r;
		while(i%len)i++;//�Ȱ��������߶�����len�������� 
		while(j%len)j--;
		//cout<<"l="<<l<<",r="<<r<<endl; 
		//cout<<"i="<<i<<",j="<<j<<endl; 
		for(int k=l;k<i;k++){//���߶���ı�������(l-i-1)
			int x=han(k);
			if(x<minn)minn=x,ans=k;
		}
		for(int k=i/len;k<=j/len;k++){//�м�ÿ����len�ĳ��ȣ�ֻ�ÿ�len���������� 
			int x=han(k);
			if(x<minn)minn=x,ans=k*len;
		}
		for(int k=j+1;k<=r;k++){//���߶���ı�������(j+1-r)
			int x=han(k);
			if(x<minn)minn=x,ans=k;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	len=10000; //��� 
	int l,r;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",find(l,r));
	}
	return 0;
} 
