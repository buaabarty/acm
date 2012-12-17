/*
ID:ybojan2
LANG:C++
TASK:agrinet
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    
    int n,map[101][101],d[101],res=0;
    bool use[101];
    fin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            fin>>map[i][j];
    for (int i=2;i<=n;i++)
        d[i]=1000000000;
    memset(use,false,sizeof(use));
    d[1]=0;
    for (int i=1;i<=n;i++)
    {
        int min=2147483647,x;
        for (int j=1;j<=n;j++)
            if ((!use[j])&&(d[j]<min)){
                                       min=d[j];
                                       x=j;
                                       }
        res+=min;
        use[x]=true;
        for (int j=1;j<=n;j++)
            if ((!use[j])&&(map[x][j]<d[j]))
               d[j]=map[x][j];
    }
    fout<<res<<endl;
    return 0;
}
