/*
ID:ybojan2
LANG:C++
TASK:numtri
*/

#include <iostream>
#include <fstream>

using namespace std;

int n,dat[1001][1001],dp[1001][1001];

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    
    
    fin>>n;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            fin>>dat[i][j];
            if (i==n) dp[i][j]=dat[i][j];
        }
    }
    for (int i=n-1;i>=1;i--)
    {
        for (int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dat[i][j];
        }
    }
    fout<<dp[1][1]<<endl;
    return 0;
}
