#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b_x;
ll b_y;
ll x;//���x 
ll y;//���y
ll dp[25][25];
ll control_x[10];//��ʵ���9����,��0-8(indice) 
ll control_y[10];
ll vis[25][25];//���Ƶ���1,������0 
ll DP(ll x,ll y){
	if(x<0||x>b_x||y<0||y>b_y||vis[x][y]) //Խ������Ѿ����� 
		return 0;
	if(dp[x][y]) 
		return dp[x][y];
	else 	
		return dp[x][y]=DP(x-1,y)+DP(x,y-1);
}
int main(){
	cin>>b_x>>b_y>>x>>y;
	dp[0][0]=1;
	ll sq1[9]={0,-1,-2,-2,-1,1,2,2,1};
	ll sq2[9]={0,2,1,-1,-2,-2,-1,1,2};
	ll control_len =0;
	for(ll i=0;i<=8;i++){//�ж���Ҫ�ӵĵ�����Խ�� 
		if(x+sq1[i]>=0&&x+sq1[i]<=b_x&&y+sq2[i]>=0&&y+sq2[i]<=b_y){
			vis[x+sq1[i]][y+sq2[i]]=1;
//			control_x[control_len] = x+sq1[i];
//			control_y[control_len] = y+sq2[i];
//			vis[control_x[control_len]][control_y[control_len]] = 1;//���Ƶ���1
//			control_len++;
			//cout<<"��"<<i<<"�����Ƶ�����!"<<" "<<"x����: "<<control_x[control_len-1]<<" "<<"y����: "<<control_y[control_len-1]<<endl;
		}
	}
	cout<<DP(b_x,b_y)<<endl;
//	cout<<"�����ǿ���ͼ:"<<endl;
//	for(int i=0;i<=b_x;i++){
//		for(int j=0;j<=b_y;j++)
//			cout<<vis[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<"�����ǿ��Ƶ������:"<<endl;
//	for(int i=0;i<control_len;i++)
//		cout<<control_x[i]<<"-"<<control_y[i]<<endl;
//	int control_min_x=100;
//	int control_min_y=100;
//	for(int i=0;i<control_len;i++){//�ұ߽��ϵĿ��Ƶ� 
//		if(control_x[i]==0)
//			control_min_y=min(control_min_y,control_y[i]);
//		if(control_y[i]==0)
//			control_min_x=min(control_min_x,control_x[i]);
//	}
//	control_min_x = min(control_min_x,b_x+1);//�����ڷ����� 
//	control_min_y = min(control_min_y,b_y+1);//�����ڷ����� 
//	cout<<"control_len = "<<control_len<<endl; 
//	cout<<"control_min_x = "<<control_min_x<<endl;
//	cout<<"control_min_y = "<<control_min_y<<endl;
//	�ȵ����Ե�0�к͵�0�д���
//	for(int i=1;i<control_min_x;i++)//��0��(control_min_x���޷������)
//		dp[i][0] = 1;
//	for(int i=1;i<control_min_y;i++)//��0��(control_min_y���޷������) 
//		dp[0][i] = 1;
//	�ٶ��������ִ��� 
//	for(int j=1;j<=b_y;j++){ //һ��һ���� 
//		for(int i=1;i<=b_x;i++){
//			if(vis[i][j]==0){//δ������
//				if(vis[i][j-1]==1&&vis[i-1][j]==1)
//					continue; 
//				else if(vis[i][j-1]==1) 
//					dp[i][j] = dp[i-1][j];
//				else if(vis[i-1][j]==1)
//					dp[i][j] = dp[i][j-1];	
//				else
//					dp[i][j] = dp[i][j-1] + dp[i-1][j];
//			}
//			else
//				continue; //�������Ƶ� 
//		}
//	}
//	cout<<"�����Ǵ�(0,0)����ÿ�����·����:"<<endl; 
//	for(int i=0;i<=b_x;i++){
//		for(int j=0;j<=b_y;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	return 0;
}
//6 6 3 3 ---> 6
//4 8 2 4 ---> 0
//8 6 0 4 ---> 1617
//20 20 4 0 --> 56477364570
