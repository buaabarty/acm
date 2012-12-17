/*
ID:ybojan2
LANG:C++
TASK:lamps
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    
    int n,c,kai[101],guan[101],lk=0,lg=0,now[101],count=0,res[17][101];
    fin>>n>>c;
    int x;
    fin>>x;
    for (;x!=-1;)
    {
        lk++;
        kai[lk]=x;
        fin>>x;
    }
    fin>>x;
    for (;x!=-1;)
    {
        lg++;
        guan[lg]=x;
        fin>>x;
    }
    for (int i=1;i<=n;i++)
        now[i]=1;
    for (int i=1;i>=0;i--)
    {
        for (int s=1;s<=n;s++)
            now[s]=1-now[s];
        for (int j=1;j>=0;j--)
        {
            for (int s=1;s<=n;s+=2)
                now[s]=1-now[s];
            for (int k=1;k>=0;k--)
            {
                for (int s=2;s<=n;s+=2)
                    now[s]=1-now[s];
                for (int t=1;t>=0;t--)
                {
                    for (int s=1;s<=n;s+=3)
                        now[s]=1-now[s];
                    bool okay=true;
                    int ss=i+j+k+t;
                    if ((ss>c)||((ss%2)!=(c%2))) continue;
                    for (int s=1;s<=lk;s++)
                        if (now[kai[s]]==0) 
                        {
                                      okay=false;
                                      break;
                        }
                    for (int s=1;s<=lg;s++)
                        if (now[guan[s]]==1)
                        {
                                        okay=false;
                                        break;
                        }
                    if (okay)
                    { 
                             count++;
                             for (int s=1;s<=n;s++)
                                 res[count][s]=now[s];
                    }
                }
            }
        }
    }
    for (int i=1;i<=count;i++)
    {
        for (int j=i+1;j<=count;j++)
        {
            bool big=false;
            for (int k=1;k<=n;k++)
            {
                if (res[i][k]!=res[j][k])
                {
                                         big=(res[i][k]>res[j][k])?true:false;
                                         break;
                }
            }
            if (big)
            {
                    int tmp;
                    for (int k=1;k<=n;k++)
                    {
                        tmp=res[i][k];
                        res[i][k]=res[j][k];
                        res[j][k]=tmp;
                    }
            }
        }
    }
    for (int i=1;i<=count;i++)
    {
        for (int j=1;j<=n;j++)
            fout<<res[i][j];
        fout<<endl;
    }
    if (count==0) fout<<"IMPOSSIBLE"<<endl;
    return 0;
}
