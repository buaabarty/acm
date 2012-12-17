/*
ID:ybojan2
LANG:C++
TASK:stamps
*/

#include <iostream>
#include <fstream>

using namespace std;

    int k,n,sum=0,res,p[201],dp[2000002];

int main()
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    
    fin>>k>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>p[i];
        sum=max(sum,p[i]);
    }
    sum*=k;
    dp[0]=0;
    for (int i=1;i<=sum+1;i++)
        dp[i]=2147483646;
    for (int i=1;i<=n;i++)
    {
        for (int j=p[i];j<=sum;j++)
            dp[j]=min(dp[j],dp[j-p[i]]+1);
    }

    for (int i=1;i<=sum+1;i++)
        if (dp[i]>k)
        {
                    res=i-1;
                    break;
        }
    fout<<res<<endl;
    return 0;
}
