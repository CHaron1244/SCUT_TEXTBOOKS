#include<bits/stdc++.h>
using namespace std;
int fx[9]={0,1,1,0,-1,-1,-1,0,1};//横方向为x 
int fy[9]={0,0,1,1,1,0,-1,-1,-1};//竖方向为y 
int a[10][10];//僵尸位置 
int create[10][10];//放炸弹的位置 
bool vis[10][10];//炸弹覆盖的位置 
int hang=4;//能拿炸弹的行数 
int lie=7;//能拿炸弹的列数 
int cnt;
int countOnes; 
int ans=900;
void check(int countOnes){
	int temp_sum=0; 
	for(int i=0;i<4;i++){//遍历create数组 
		for(int j=0;j<7;j++){
			if(create[i][j]==1){//这个位置有炸弹 
				int ii=i+1;//原数组中的位置 
				int jj=j+1;//原数组中的位置
				int temp=(ii==2||ii==3?175:150);
				temp_sum+=temp;
				for(int k=0;k<9;k++)
					if(ii+fy[k]>=0&&ii+fy[k]<=5&&jj+fx[k]>=0&&jj+fx[k]<=8){//在范围内 
						//cout<<"标记此处!"<<endl;
						vis[ii+fy[k]][jj+fx[k]]=1;
					}
			}
		}
	}
	bool flag=0;//判断是否每个位置上的僵尸都会被炸到 
	for(int i=0;i<6;i++)
		for(int j=0;j<9;j++)
			if(vis[i][j]==0&&a[i][j]==1){//有僵尸但是炸不到 
				flag=1;
				break;
			}
	if(flag==0){//每个僵尸都被炸到了 
		ans=min(ans,temp_sum);
	}
	memset(vis,0,sizeof(vis));
} 
void generateCombinations(int row, int col, int countOnes) {
    if (countOnes == 0) {// 达到需要的1的数量时，打印数组
    	cnt++;
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 7; j++) 
//            	cout << create[i][j] << " ";
//            cout << std::endl;
//        }
		check(countOnes);//此时进行检查 
        return;
    }
    for (int i = row; i < 4; i++) { //在当前位置放置1，并递归生成剩余1的位置
        for (int j = col; j < 7; j++) {
            create[i][j] = 1;
            generateCombinations(i, j + 1, countOnes - 1);
            create[i][j] = 0; // 恢复为0，继续尝试下一个位置放置1
        }
        col = 0; // 重置列索引，从下一行的第一列开始尝试放置1
    }
}
int main(){
	bool all_one=1;//是否全是1 
	bool all_zero=1;//是否全是0 
	int exist_one=0;
	int exist_zero=0;
	for(int i=0;i<6;i++)
		for(int j=0;j<9;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				exist_one++;
			if(a[i][j]==0)
				exist_zero++;
		}			
	if(!exist_one){
		cout<<0<<endl;
		return 0;
	}
	for(int countOnes=5;countOnes>=0;countOnes--){
		generateCombinations(0, 0, countOnes);
	}	
	cout<<ans<<endl;
	return 0;
} 
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0 0
1 1 1 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 
*/
