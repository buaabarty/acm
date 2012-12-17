/*
ID:ybojan2
LANG:C++
TASK:buylow
*/
#include <iostream>
#include <stdio.h>
using namespace std;
//ifstream fin("buylow.in");
//ofstream fout("buylow.out");

int main()
{    int n,num[5001];
    int dp[5001],maxr=0,l[5001];
    int count[5001][100];
    int sum[200],ls=0;
    memset(dp,0,sizeof(dp));
    memset(count,0,sizeof(count));
    memset(l,0,sizeof(l));
    memset(sum,0,sizeof(sum));
    cin>>n;
    for (int i=1;i<=n;i++) cin>>num[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
            if (num[j]>num[i]) dp[i]=max(dp[j],dp[i]);
        dp[i]++;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i-1;j>=1;j--)
            if ((dp[j]+1==dp[i])&&(num[j]>num[i])){
                                                  bool okay=true;
                                                  for (int k=j+1;k<i;k++) if (num[j]==num[k]){
                                                      okay=false;break;
                                                  }
                                                  if (okay) {
                                                            for (int k=1;k<=l[j];k++) count[i][k]+=count[j][k];
                                                            l[i]=max(l[i],l[j]);
                                                            for (int k=1;k<=l[i];k++)
                                                            {
                                                                count[i][k+1]+=count[i][k]/10;
                                                                count[i][k]%=10;
                                                            }
                                                            if (count[i][l[i]+1]>0) l[i]++;
                                                            }
                                                  }
        if (l[i]==0) {
                     count[i][1]=1;
                     l[i]=1;
                     }
    }
    for (int i=1;i<=n;i++) maxr=max(maxr,dp[i]);
    cout<<maxr<<" ";
    for (int i=n;i>=1;i--)
        if ((dp[i]==maxr)){
                           bool okay=true;
                           for (int j=i+1;j<=n;j++) if (num[i]==num[j]){
                               okay=false;break;
                           }
                           if (!okay) continue;
                           for (int j=1;j<=l[i];j++)
                               sum[j]+=count[i][j];
                           ls=max(ls,l[i]);
                           for (int j=1;j<=ls;j++)
                           {
                               sum[j+1]+=sum[j]/10;
                               sum[j]%=10;
                           }
                           if (sum[ls+1]>0) ls++;
                           }
    for (int i=ls;i>=1;i--) cout<<sum[i];
    cout<<endl;
    return 0;
}
