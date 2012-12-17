/*
ID:ybojan2
LANG:C++
TASK:ariprog
*/

#include <iostream>
#include <fstream>

using namespace std;

int max(int a,int b)
{
    return ((a>b)?a:b);
}

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    int n,m,pre[125001],next[125001],last=0;
    bool dsq[125001];
    fin>>n>>m;
    for (int i=0;i<=2*m*m;i++)
        dsq[i]=false;
    
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=m;j++)
        {
            dsq[i*i+j*j]=true;
        }
    }
    

    m=m*m*2;       
    
    pre[0]=-1;
    for (int i=1;i<=m;)
    {
        for (;!dsq[i];i++){}
        pre[i]=last;
        last=i;
        i++;
    }
    next[m]=m+1;
    last=m;
    for (int i=m-1;i>=0;)
    {
        for (;!dsq[i];i--){}
        next[i]=last;
        last=i;
        i--;
    }

    int dp[125001];
    for (int i=0;i<=m;i++)
        dp[i]=0;
    bool flag=false;
    for (int i=1;i<=m/(n-1);i++)
    {
        int j;
        for (j=m;j>=0;)
        {
            dp[j]=1;
            j=pre[j];
        }
        for (j=m-i;(!dsq[j]);j--){}
        for (;j>=0;)
        {
            dp[j]=max(dp[j],dp[j+i]+1);
            j=pre[j];
        }
        for (j=0;j<=m;)
        {
            if (dp[j]>=n)
            {
                         fout<<j<<" "<<i<<endl;
                         flag=true;
                         }
            j=next[j];
        }

    }
    
    if (!flag) fout<<"NONE"<<endl;
    return 0;
}
