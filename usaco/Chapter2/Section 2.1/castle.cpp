/*
ID:ybojan2
LANG:C++
TASK:castle
*/

#include <iostream>
#include <fstream>

using namespace std;

bool map[52][52][52][52]={false};
int n,m,step[4][2]={{1,0},{-1,0},{0,1},{0,-1}},cnt=0;
int color[51][51],maxv=0,sum=0,v[10000];

int max(int x,int y)
{
    return ((x>y)?x:y);
}

int floodfill(int x,int y,int sign)
{
     int tt=1;
     color[x][y]=sign;
     for (int i=0;i<=3;i++)
     {
         int x1=x+step[i][0],y1=y+step[i][1];
         if ((x1>=1)&&(x1<=n)&&(y1>=1)&&(y1<=m)&&(map[x][y][x1][y1])&&(color[x1][y1]==0))
         {
                      tt+=floodfill(x1,y1,sign);
         }
     }
     return tt;
}

int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    
    fin>>m>>n;
    for (int i1=1;i1<=n;i1++)
        for (int i2=1;i2<=m;i2++)
            for (int i3=1;i3<=n;i3++)
                for (int i4=1;i4<=m;i4++)
                    map[i1][i2][i3][i4]=true;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int x;
            fin>>x;
            if ((x&1)==1) map[i][j][i][j-1]=false;
            if ((x&2)==2) map[i][j][i-1][j]=false;
            if ((x&4)==4) map[i][j][i][j+1]=false;
            if ((x&8)==8) map[i][j][i+1][j]=false;
            color[i][j]=0;
        }    
    }
    

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (color[i][j]==0)
            {
                               cnt++;
                               v[cnt]=floodfill(i,j,cnt);
                               maxv=max(maxv,v[cnt]);
            }
        }
    }
    
    fout<<cnt<<endl;
    fout<<maxv<<endl;
    for (int i=n;i>=1;i--)
    {
        for (int j=1;j<=m;j++)
        {
            if ((color[i][j]!=color[i-1][j])&&(i>1))
            {
               sum=max(v[color[i][j]]+v[color[i-1][j]],sum);
            }
            if ((color[i][j]!=color[i][j+1])&&(j<m))
            {
               sum=max(v[color[i][j]]+v[color[i][j+1]],sum);
            }            
        }
    }
    fout<<sum<<endl;
    for (int j=1;j<=m;j++)
    {
        for (int i=n;i>=1;i--)
        {
            if ((color[i][j]!=color[i-1][j])&&(i>1))
            {
               if (v[color[i][j]]+v[color[i-1][j]]==sum)
               {
                    fout<<i<<" "<<j<<" N"<<endl;
                    return 0;
               }
            }
            if ((color[i][j]!=color[i][j+1])&&(j<m))
            {
               if (v[color[i][j]]+v[color[i][j+1]]==sum)
               {
                    fout<<i<<" "<<j<<" E"<<endl;
                    return 0;
               }
            }            
        }
    }
    return 0;
}
