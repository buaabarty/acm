/*
ID:ybojan2
LANG:C++
TASK:fc
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
 struct POINT
 {
          double x,y;
 };
double multiply(POINT p1,POINT p2,POINT p0)
 {
          return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
double dis(POINT p1,POINT p2)
{
          return(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
void Graham_scan(POINT POINTSet[],POINT ch[],int n,int &len)
{
          int i,j,k=0,top=2;
          POINT tmp;
         for(i=1;i<n;i++)
    if((POINTSet[i].y<POINTSet[k].y)||((POINTSet[i].y==POINTSet[k].y)&&(POINTSet[i].x<POINTSet[k].x)))
          k=i;
          tmp=POINTSet[0];
          POINTSet[0]=POINTSet[k];
          POINTSet[k]=tmp;
          for (i=1;i<n-1;i++)
              {
              k=i;
              for (j=i+1;j<n;j++)
                  if ( (multiply(POINTSet[j],POINTSet[k],POINTSet[0])>0) ||
                           ((multiply(POINTSet[j],POINTSet[k],POINTSet[0])==0)
         &&(dis(POINTSet[0],POINTSet[j])<dis(POINTSet[0],POINTSet[k]))))
                      k=j;
              tmp=POINTSet[i];
              POINTSet[i]=POINTSet[k];
              POINTSet[k]=tmp;
    }
          ch[0]=POINTSet[0];
          ch[1]=POINTSet[1];
          ch[2]=POINTSet[2];
          for (i=3;i<n;i++)
    {
              while(multiply(POINTSet[i],ch[top],ch[top-1])>=0)
      top--;
              ch[++top]=POINTSet[i];
    }
          len=top+1;
      }
double polygonarea(POINT *polygon,int N)
 {
          int i,j;
          double area = 0;
          for (i=0;i<N;i++)
    {
              j = (i + 1) % N;
              area += polygon[i].x * polygon[j].y;
              area -= polygon[i].y * polygon[j].x;
    }
          area /= 2;
          return(area < 0 ? -area : area);
}
POINT a[10001],b[10001];
double sqr(double x)
{
    return x * x;
}
double dist(POINT x, POINT y)
{
    return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y));
}
int main()
{
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    int n,m;
    scanf("%d", &n);
    for (int i = 0; i < n;  ++i)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    Graham_scan(a,b,n,m);
    double sum = 0;
    for (int i = 0; i < m; ++i)
        sum += dist(b[i], b[(i + 1) % m]);
    printf("%.2f\n", sum);
 return 0;
}
