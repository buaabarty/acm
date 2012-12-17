/*
ID:ybojan2
LANG:C++
TASK:money
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("money.in");
    ofstream fout("money.out");
    
    int v,n,p;
    long long dp[10001];
    
    fin>>v>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=v;i++)
    {
        fin>>p;
        for (int j=p;j<=n;j++)
            dp[j]+=dp[j-p];
    }
    
    fout<<dp[n]<<endl;
    return 0;
}
