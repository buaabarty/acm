/*
ID:ybojan2
LANG:C++
TASK:concom
*/

#include <iostream>
#include <fstream>

using namespace std;

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

int n,con[101][101],use[101][101],maxn,x[10001],y[10001],cnt=0;

int main()
{
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    
    memset(con,0,sizeof(con));
    memset(use,false,sizeof(use));
    
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        int a,b,c;
        fin>>a>>b>>c;
        con[a][b]=c;
        maxn=max(max(a,b),maxn);
    }
    n=maxn;
    for (int i=1;i<=n;i++) use[i][i]=true;
    for (;;)
    {
        bool find=false;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i==j) continue;
                if ((con[i][j]>50)&&(!use[i][j]))
                {
                                 find=true;
                                 cnt++;
                                 x[cnt]=i;
                                 y[cnt]=j;
                                 use[i][j]=true;
                }
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int k=1;k<=n;k++)
            {
                if (use[i][k]) continue;
                int sum=0;
                for (int j=1;j<=n;j++)
                {
                    if (!use[i][j]) continue;
                    sum+=con[j][k];
                }
                if (sum>50)
                {
                           find=true;
                           cnt++;
                           x[cnt]=i;
                           y[cnt]=k;
                           use[i][k]=true;
                }
                
            }
        }
        if  (!find) break;
    }
    
    for (int i=1;i<=cnt;i++)
    {
        for (int j=i+1;j<=cnt;j++)
        {
            if (((x[i]==x[j])&&(y[i]>y[j]))||(x[i]>x[j]))
            {
                                                         swap(x[i],x[j]);
                                                         swap(y[i],y[j]);
            }
        }
    }
    for (int i=1;i<=cnt;i++)
        fout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}
