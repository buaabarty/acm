/*
ID:ybojan2
LANG:C++
TASK:inflate
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    
    int t,m,time,score,dp[10001];
    memset(dp,0,sizeof(dp));
    fin>>t>>m;
    for (int i=1;i<=m;i++)
    {
        fin>>score>>time;
        for (int j=time;j<=t;j++)
            dp[j]=max(dp[j],dp[j-time]+score);
    }
    
    fout<<dp[t]<<endl;
    return 0;
}
