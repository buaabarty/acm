/*
ID:ybojan2
LANG:C++
TASK:range
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    
    int n,dat[300][300],dp[300][300],cnt[300];
    fin>>n;
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            char c;
            fin>>c;
            if (c=='1') dat[i][j]=1;
            else dat[i][j]=0;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (dat[i][j]==1) dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
    for (int i=1;i<=n;i++)        
        for (int j=1;j<=n;j++)
            for (int k=2;k<=dp[i][j];k++)
                cnt[k]++;
    for (int i=2;i<=n;i++)
        if (cnt[i]!=0) fout<<i<<" "<<cnt[i]<<endl;
    return 0;
}
