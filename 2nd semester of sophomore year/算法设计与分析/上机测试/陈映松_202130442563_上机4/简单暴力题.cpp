#include<bits/stdc++.h>
using namespace std;
int fx[9]={0,1,1,0,-1,-1,-1,0,1};//�᷽��Ϊx 
int fy[9]={0,0,1,1,1,0,-1,-1,-1};//������Ϊy 
int a[10][10];//��ʬλ�� 
int create[10][10];//��ը����λ�� 
bool vis[10][10];//ը�����ǵ�λ�� 
int hang=4;//����ը�������� 
int lie=7;//����ը�������� 
int cnt;
int countOnes; 
int ans=900;
void check(int countOnes){
	int temp_sum=0; 
	for(int i=0;i<4;i++){//����create���� 
		for(int j=0;j<7;j++){
			if(create[i][j]==1){//���λ����ը�� 
				int ii=i+1;//ԭ�����е�λ�� 
				int jj=j+1;//ԭ�����е�λ��
				int temp=(ii==2||ii==3?175:150);
				temp_sum+=temp;
				for(int k=0;k<9;k++)
					if(ii+fy[k]>=0&&ii+fy[k]<=5&&jj+fx[k]>=0&&jj+fx[k]<=8){//�ڷ�Χ�� 
						//cout<<"��Ǵ˴�!"<<endl;
						vis[ii+fy[k]][jj+fx[k]]=1;
					}
			}
		}
	}
	bool flag=0;//�ж��Ƿ�ÿ��λ���ϵĽ�ʬ���ᱻը�� 
	for(int i=0;i<6;i++)
		for(int j=0;j<9;j++)
			if(vis[i][j]==0&&a[i][j]==1){//�н�ʬ����ը���� 
				flag=1;
				break;
			}
	if(flag==0){//ÿ����ʬ����ը���� 
		ans=min(ans,temp_sum);
	}
	memset(vis,0,sizeof(vis));
} 
void generateCombinations(int row, int col, int countOnes) {
    if (countOnes == 0) {// �ﵽ��Ҫ��1������ʱ����ӡ����
    	cnt++;
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 7; j++) 
//            	cout << create[i][j] << " ";
//            cout << std::endl;
//        }
		check(countOnes);//��ʱ���м�� 
        return;
    }
    for (int i = row; i < 4; i++) { //�ڵ�ǰλ�÷���1�����ݹ�����ʣ��1��λ��
        for (int j = col; j < 7; j++) {
            create[i][j] = 1;
            generateCombinations(i, j + 1, countOnes - 1);
            create[i][j] = 0; // �ָ�Ϊ0������������һ��λ�÷���1
        }
        col = 0; // ����������������һ�еĵ�һ�п�ʼ���Է���1
    }
}
int main(){
	bool all_one=1;//�Ƿ�ȫ��1 
	bool all_zero=1;//�Ƿ�ȫ��0 
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
