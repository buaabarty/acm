/*
ID:ybojan2
LANG:C++
TASK:calfflac
*/

#include <iostream>
#include <fstream>

using namespace std;

int max(int x,int y)
{
    return ((x>y)?x:y);
}

int main()
{
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");
    
    char c,dat[30000],org[30000];
    int len=0,sl=0,dd[30000],dp[30000];
    while (!fin.eof())
    {
          sl++;
          c=fin.get();
          org[sl]=c;
          if (((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z'))) 
          {
                                                          len++;
                                                          if (c>='a') c=c-'a'+'A';
                                                          dat[len]=c;
                                                          dd[len]=sl;
                                                          }
    }
    
    dp[1]=1;
    for (int i=2;i<=len;i++)
    {
        dp[i]=1;
        if (i>dp[i-1])
        {
                      if (dat[i]==dat[i-dp[i-1]-1]) dp[i]=max(dp[i],dp[i-1]+2);
                      }
        if (dat[i]==dat[i-1]) dp[i]=max(dp[i],2);
    }
    int max=0;
    for (int i=1;i<=len;i++)
    {
        if (dp[i]>max) max=dp[i];
    }
    
    
    fout<<max<<endl;
    for (int i=1;i<=len;i++)
    {
        if (dp[i]==max)
        {
                       for (int j=dd[i-dp[i]+1];j<=dd[i];j++)
                           fout<<org[j];
                       fout<<endl;
                       break;
        }
    }
    return 0;
}
