#include "stdio.h"
#include "math.h"
#include <cstdio>  
#include "algorithm"
#define MAX 100005 
const double inf = 1e20;
struct Point{
    double x;
    double y;
};
Point p[MAX];
int ans[MAX];
double dis(Point p1,Point p2)
{
    return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}
bool cmpy(const int & a,int& b)
{
     return p[a].y < p[b].y;
}
bool compxy(const Point& p1,Point& p2)
{
    if(p1.x!=p2.x)
        return p1.x<p2.x;
    return p1.y<p2.y;
}

double min(double a,double b)
{
    return a<b?a:b;
}
double divide(int left,int right)
{
    double d=inf;
    /*����ָֻ��һ���㣬��ô�����ԵĻ�������Ȼ����inf��*/
    if(left==right)
        return d;
    //�������ж��Ƿ�Ϊֻ�������㣬���ֻ��������Ļ���ôֱ����⡣
    if(left+1==right)
        return dis(p[left],p[right]);
    //���Ƴ�2����������к���Ļ��֣�ʹ���������߱��ִ�����ȸ�����
    int mid=(left+right)>>1; 
    double d1=divide(left,mid);
    double d2=divide(mid+1,right);
    d=min(d1,d2);
    int i,j,k=0;
    //ͨ��������ȷ��[X-d,X+d]����
    for(i=left;i<=right;i++)
    {
        if(fabs(p[mid].x-p[i].x)<=d)
           ans[k++]=i;
    }
    //ͨ������ȷ����д�㰴������������
    std::sort(ans, ans + k, cmpy);//����ɨ��
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k && p[ans[j]].y-p[ans[i]].y<d;j++)
        {
            double distance=dis(p[ans[i]],p[ans[j]]);
            if(distance < d)
                d=distance;
        }
    }
    return d;
}
int main()
{
  int  i,j,N;
  while(scanf("%d",&N) && N!=0)
  {
     for(i=0;i<N;i++)
         scanf("%lf%lf",&p[i].x,&p[i].y);
     std::sort(p,p+N,compxy);//���ﰴ�պ������СԤ�������ú���������λ��
     printf("%.2lf\n",divide(0,N-1)/2);
  }
  return 0;
}

