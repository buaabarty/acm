/*
ID:ybojan2
LANG:C++
TASK:spin
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    
    int v[6],d[6][360],w[6],s[6][6],t[6][6];
    memset(d,0,sizeof(d));
    for (int i=1;i<=5;i++)
    {
        fin>>v[i]>>w[i];
        for (int j=1;j<=w[i];j++)
        {
            fin>>s[i][j]>>t[i][j];
        }
    }
    for (int time=0;time<=360;time++)
    {
        int now[360];
        for (int j=0;j<=359;j++)
            now[j]=1;
        for (int j=1;j<=5;j++)
        {
            int ss[360];
            memset(ss,0,sizeof(ss));
            for (int k=1;k<=w[j];k++)
            {
                for (int m=s[j][k];m<=s[j][k]+t[j][k];m++)
                    ss[m%360]=1;
            }
            for (int k=0;k<=359;k++)
                now[k]=now[k]&ss[k];
        }
        bool exist=false;
        for (int j=0;j<=359;j++)
            if (now[j]==1) {
                           exist=true;
                           break;
                           }
        if (exist) {
                   fout<<time<<endl;
                   return 0;
                   }
        for (int j=1;j<=5;j++)
        {
            int news[360];
            for (int k=1;k<=w[j];k++)
            {
                s[j][k]+=v[j];
                s[j][k]%=360;
            }
        }
    }
    fout<<"none"<<endl;
    return 0;
}
