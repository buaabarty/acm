/*
ID:ybojan2
LANG:C++
TASK:game1
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    
    int n,num[101],dp[101][101],sum[101][101];
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>num[i];
    for (int i=1;i<=n;i++)
    {
        sum[i][i]=num[i];
        for (int j=i+1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+num[j];
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++)
        dp[i][i]=num[i];
    for (int l=1;l<n;l++)
        for (int i=1;i<=n-l;i++)
            dp[i][i+l]=sum[i][i+l]-min(dp[i][i+l-1],dp[i+1][i+l]);
    fout<<dp[1][n]<<" "<<sum[1][n]-dp[1][n]<<endl;
    return 0;
}
