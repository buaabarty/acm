/*
ID:ybojan2
LANG:C++
TASK:prefix
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    
    string str[201],now,ss;
    int len=0,l,sl=0;
    char m[200001];
    
    fin>>now;
    while (now!=".")
    {
          len++;
          str[len]=now;
          fin>>now;
    }
    fin>>ss;
    while (!fin.eof())
    {
          l=ss.size();
          for (int i=sl+1;i<=sl+l;i++)
              m[i]=ss[i-sl-1];
          sl+=l;
          fin>>ss;
    }
    bool dp[200001];
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for (int i=1;i<=sl;i++)
    {
        for (int j=1;j<=len;j++)
        {
            bool okay=true;
            int ll=str[j].length();
            if (i<ll) continue;
            for (int k=0;k<ll;k++)
                if (str[j][k]!=m[i-ll+1+k]) 
                {
                                            okay=false;
                                            break;
                                            }
            if (okay) dp[i]=(dp[i]||dp[i-ll]);
        }
    }
    for (int i=sl;i>=0;i--)
        if (dp[i]) 
        {
                    fout<<i<<endl;
                    break;
        }
    return 0;
}
