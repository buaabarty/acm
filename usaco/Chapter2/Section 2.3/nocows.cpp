/*
ID:ybojan2
LANG:C++
TASK:nocows
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    int n,k,dp[200][200];  
    fin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for (int i=3;i<=n;i+=2)
        for (int j=1;j<=i-2;j+=2)
            for (int k1=1;k1<=(j+1)/2;k1++)
                for (int k2=1;k2<=(i-j)/2;k2++)
                {
                    dp[i][max(k1,k2)+1]+=dp[j][k1]*dp[i-j-1][k2];
                    dp[i][max(k1,k2)+1]%=9901;
                }
    fout<<dp[n][k]<<endl;
    return 0;
}
