#include<bits/stdc++.h>
using namespace std;
void insertSort(int *a,int len,int& sum){//�����±�:1-len 
	for(int i=2;i<=len;i++){//�ӵڶ�������ʼ�� 
		int temp = a[i];
		int pos=1;
		for(int j=i;j>=1;j--){
			if(a[j] < a[i]){
				pos = j+1;
				break;
			}
		}
		for(int k=i-1;k>=pos;k--){
			a[k+1] = a[k];
			sum++;
		}
		a[pos] = temp;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int cnt=0;//���鳤�� 
		int sum=0;//���ս�� 
		int a[1010];//�涨�����1��ʼ���� 
		memset(a,0,sizeof(a));
		int num=0;//��¼Ҫ��������Ԫ�� 
		bool flag=0;//�жϸ��� 
		for(int i=0;i<s.length();i++){
			if(s[i]=='-')
				flag=1;
			else if(s[i]>='0'&&s[i]<='9')
				num=num*10+s[i]-'0';
			else if(s[i]==','){
				if(flag==1)
					num*=-1;
				a[++cnt] = num;		
				num=0;
				flag=0;
			}
		}
		if(flag==1)
			num*=-1;
		a[++cnt] = num;//�����һ����
		insertSort(a,cnt,sum);
		cout<<sum<<endl;
	}
	return 0;
} 
