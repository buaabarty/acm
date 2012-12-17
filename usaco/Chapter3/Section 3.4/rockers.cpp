/*
ID:ybojan2
LANG:C++
TASK:rockers
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");
    
    int n,t,m,dp[21][21],p[21];
    fin>>n>>t>>m;
    for (int i=1;i<=n;i++)
        fin>>p[i];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            int q[21],tt=0;
            for (int k=1;k<=20;k++) q[k]=100000000;
            q[0]=-10000000;
            for (int k=j;k>=1;k--)
            {
                if (p[k]<q[tt+1]){
                                  tt++;
                                  q[tt]=p[k];
                                  }
                int s=tt;
                while (q[s]<q[s-1])
                {
                      swap(q[s],q[s-1]);
                      s--;
                }
                int sum=0;
                for (s=1;s<=tt+1;s++)
                {
                    sum+=q[s];
                    if (sum>t) break;
                }
                dp[i][j]=max(dp[i][j],dp[i-1][k-1]+s-1);
            }
        }
    fout<<dp[m][n]<<endl;
    return 0;
}
