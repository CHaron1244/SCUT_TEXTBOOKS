#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b_x;
ll b_y;
ll x;//马的x 
ll y;//马的y
ll dp[25][25];
ll control_x[10];//其实最多9个点,用0-8(indice) 
ll control_y[10];
ll vis[25][25];//控制点置1,其余置0 
ll DP(ll x,ll y){
	if(x<0||x>b_x||y<0||y>b_y||vis[x][y]) //越界或者已经访问 
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
	for(ll i=0;i<=8;i++){//判断需要加的点有无越界 
		if(x+sq1[i]>=0&&x+sq1[i]<=b_x&&y+sq2[i]>=0&&y+sq2[i]<=b_y){
			vis[x+sq1[i]][y+sq2[i]]=1;
//			control_x[control_len] = x+sq1[i];
//			control_y[control_len] = y+sq2[i];
//			vis[control_x[control_len]][control_y[control_len]] = 1;//控制点置1
//			control_len++;
			//cout<<"第"<<i<<"个控制点有用!"<<" "<<"x坐标: "<<control_x[control_len-1]<<" "<<"y坐标: "<<control_y[control_len-1]<<endl;
		}
	}
	cout<<DP(b_x,b_y)<<endl;
//	cout<<"下面是控制图:"<<endl;
//	for(int i=0;i<=b_x;i++){
//		for(int j=0;j<=b_y;j++)
//			cout<<vis[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<"下面是控制点的坐标:"<<endl;
//	for(int i=0;i<control_len;i++)
//		cout<<control_x[i]<<"-"<<control_y[i]<<endl;
//	int control_min_x=100;
//	int control_min_y=100;
//	for(int i=0;i<control_len;i++){//找边界上的控制点 
//		if(control_x[i]==0)
//			control_min_y=min(control_min_y,control_y[i]);
//		if(control_y[i]==0)
//			control_min_x=min(control_min_x,control_x[i]);
//	}
//	control_min_x = min(control_min_x,b_x+1);//限制在方格内 
//	control_min_y = min(control_min_y,b_y+1);//限制在方格内 
//	cout<<"control_len = "<<control_len<<endl; 
//	cout<<"control_min_x = "<<control_min_x<<endl;
//	cout<<"control_min_y = "<<control_min_y<<endl;
//	先单独对第0行和第0列处理
//	for(int i=1;i<control_min_x;i++)//第0列(control_min_x是无法到达的)
//		dp[i][0] = 1;
//	for(int i=1;i<control_min_y;i++)//第0行(control_min_y是无法到达的) 
//		dp[0][i] = 1;
//	再对其他部分处理 
//	for(int j=1;j<=b_y;j++){ //一列一列填 
//		for(int i=1;i<=b_x;i++){
//			if(vis[i][j]==0){//未被控制
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
//				continue; //跳过控制点 
//		}
//	}
//	cout<<"下面是从(0,0)到达每个点的路径数:"<<endl; 
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
