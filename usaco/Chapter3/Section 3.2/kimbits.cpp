/*
ID:ybojan2
LANG:C++
TASK:kimbits
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    
    long long n,l,t,c[32][32],f[32][32];
    
    fin>>n>>l>>t;
    memset(c,0,sizeof(c));
    for (int i=0;i<=n;i++)
        c[i][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    for (int i=0;i<=n;i++)
        f[0][i]=1;
    for (int i=1;i<=n;i++)
    {
        f[i][0]=1;
        for (int j=1;j<=n;j++)
            f[i][j]=f[i][j-1]+c[i][j];
    }
    for (int i=n;i>=1;i--)
    {
        if (t>f[i-1][l]){
                         fout<<1;
                         t-=f[i-1][l];
                         l--;
                         }
        else {
             fout<<0;
             }
    }
    fout<<endl;
    return 0;
}
