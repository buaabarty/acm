#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

struct data{
       int x,y,d;
}q[10000];
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
bool use[40][40];
int l,r,n,m,x[1001],y[1001],kx,ky,d[40][40][40][40],tt=0,res=2147483647,step[8][2]={{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
string str;
int main()
{
    char cy;
    cin>>n>>m;
    cin>>cy>>kx;
    ky=cy-'A'+1;
    while (!cin.eof())
    {
          tt++;
          cin>>cy>>x[tt];
          y[tt]=cy-'A'+1;
    }
    tt++;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                for (int t=1;t<=m;t++)
                    d[i][j][k][t]=10000000;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
           memset(q,0,sizeof(q));
           memset(use,false,sizeof(use));
           l=1;
           r=1;
           q[1].x=i;
           q[1].y=j;
           use[i][j]=true;
           d[i][j][i][j]=0;
           for(;;)
           {
                  for (int k=0;k<=7;k++)
                  {
                      int xx=q[l].x+step[k][0],yy=q[l].y+step[k][1];
                      if (((xx>=1)&&(xx<=n)&&(yy>=1)&&(yy<=m)&&(!use[xx][yy]))){
                                                                                r++;
                                                                                q[r].x=xx;
                                                                                q[r].y=yy;
                                                                                d[i][j][xx][yy]=q[l].d+1;
                                                                                q[r].d=d[i][j][xx][yy];
                                                                                use[xx][yy]=true;
                                                                                }
                  }
                  l++;
                  if (l>r) break;
           }
        }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int minn=2147483647,sum=0;
            for (int k=1;k<=tt;k++)
                sum+=d[i][j][x[k]][y[k]];
            if (sum+max(iabs(kx-i),iabs(ky-j))<minn) minn=sum+max(iabs(kx-i),iabs(ky-j));
            for (int xx=max(1,kx-2);xx<=min(n,kx+2);xx++)
                for (int yy=max(1,ky-2);yy<=min(m,ky+2);yy++)
                    for (int k=1;k<=tt;k++)
                    {
                        int now=sum-d[i][j][x[k]][y[k]]+d[x[k]][y[k]][xx][yy]+d[xx][yy][i][j]+max(iabs(kx-xx),iabs(ky-yy));
                        if (now<minn) minn=now;
                    }
            if (minn<res) res=minn;
        }
    cout<<res<<endl;
    return 0;
}
