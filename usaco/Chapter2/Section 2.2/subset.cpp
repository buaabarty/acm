/*
ID:ybojan2
LANG:C++
TASK:subset
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    
    int n,max;
    unsigned long dp[10000];
    fin>>n;
    max=(n*(n+1))/2;
    if (max&1==1) 
    {
                  fout<<0<<endl;
                  return 0;
                  }
    max/=2;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=max;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
    }
    fout<<dp[max]/2<<endl;
    return 0;
}
