#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1e5 + 10;
ll n;
int a[maxn];
int dp[maxn];//dp[i]=��<=i��λ�ÿ��Ե�����Զλ�� 
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
//	dp[0]=a[0];
//	int temp_max=dp[0];//dp�е����ֵ 
//	for(int i=1;i<n;i++){ 
//		dp[i]=max(dp[i-1],a[i]+i);
//		if(dp[i]>=n-1){ //�����黹���� 
//			cout<<n-1<<endl; //max
//			return 0;
//		}
//		else //���dpû�д���n����,��¼dp�е����ֵ 
//			temp_max=max(temp_max,dp[i]);		
//	}
//	cout<<temp_max<<endl;

	int right=0;//��ǰ�����������
	for(int i=0;i<n;i++){
		//�����ǰ�±�С�ڵ��ڸ��º�Ŀǰ�����������,֤��������������������һ��λ��
		//���ڵĻ���������һ��ѭ����֤����ǰ���ɴ
		if(i <= right){
			right = max(right,i+a[i]);//���µ�ǰ�����������
			if(right >= n-1){ //�Ѿ����� 
				cout<<n-1<<endl; //max
				return 0;
			}
		}
	}
	cout<<right<<endl;
	return 0;
}
