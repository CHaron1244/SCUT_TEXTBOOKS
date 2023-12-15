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
    /*这里指只有一个点，那么最近点对的话距离自然就是inf了*/
    if(left==right)
        return d;
    //这里是判断是否为只有两个点，如果只有两个点的话那么直接求解。
    if(left+1==right)
        return dis(p[left],p[right]);
    //右移除2，对区域进行合理的划分，使得左右两边保持大致相等个数点
    int mid=(left+right)>>1; 
    double d1=divide(left,mid);
    double d2=divide(mid+1,right);
    d=min(d1,d2);
    int i,j,k=0;
    //通过横坐标确定[X-d,X+d]区域
    for(i=left;i<=right;i++)
    {
        if(fabs(p[mid].x-p[i].x)<=d)
           ans[k++]=i;
    }
    //通过排序，确定这写点按照纵坐标升序
    std::sort(ans, ans + k, cmpy);//线性扫描
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
     std::sort(p,p+N,compxy);//这里按照横坐标大小预排序，利用横坐标求中位线
     printf("%.2lf\n",divide(0,N-1)/2);
  }
  return 0;
}

