/*
ID:ybojan2
LANG:C++
TASK:shopping
*/

#include <iostream>
#include <fstream>

using namespace std;

int s,p[200],c[200][6],tt=0,t[6],pp[6],nn[6],dp[6][6][6][6][6];

int ord(int x)
{
    for (int i=1;i<=tt;i++)
        if (x==nn[i]) return i;
    tt++;
    nn[tt]=x;
    return tt;
    
}

int main()
{
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    
    fin>>s;
    memset(c,0,sizeof(c));
    for (int i=1;i<=s;i++)
    {
        int n;
        fin>>n;
        for (int j=1;j<=n;j++)
        {
            int cc,k;
            fin>>cc>>k;
            c[i][ord(cc)]=k;
        }
        fin>>p[i];
    }
    int b;
    fin>>b;
    for (int i=1;i<=b;i++)
    {
        int cc;
        fin>>cc;
        fin>>t[ord(cc)]>>pp[ord(cc)];
        s++;
        p[s]=pp[ord(cc)];
        c[s][ord(cc)]=1;
        
    }
    for (int i1=0;i1<=t[1];i1++)
        for (int i2=0;i2<=t[2];i2++)
            for (int i3=0;i3<=t[3];i3++)
                for (int i4=0;i4<=t[4];i4++)
                    for (int i5=0;i5<=t[5];i5++)
                    {
                        dp[i1][i2][i3][i4][i5]=i1*pp[1]+i2*pp[2]+i3*pp[3]+i4*pp[4]+i5*pp[5];
                        for (int i=1;i<=s;i++)
                        {
                            int t1=max(i1-c[i][1],0),t2=max(i2-c[i][2],0),t3=max(i3-c[i][3],0),t4=max(i4-c[i][4],0),t5=max(i5-c[i][5],0);
                            if (dp[t1][t2][t3][t4][t5]+p[i]<dp[i1][i2][i3][i4][i5]) dp[i1][i2][i3][i4][i5]=dp[t1][t2][t3][t4][t5]+p[i];
                        }
                    }
    fout<<dp[t[1]][t[2]][t[3]][t[4]][t[5]]<<endl;
    return 0;
}
