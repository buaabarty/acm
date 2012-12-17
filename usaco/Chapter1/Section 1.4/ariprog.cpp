/*
ID:ybojan2
LANG:C++
TASK:ariprog
*/

#include <iostream>
#include <fstream>

using namespace std;

int rl=0,a[20000],b[20000];

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}


int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    int n,m,num[30000],len=0;
    bool dsq[125001];
    fin>>n>>m;
    for (int i=0;i<=125000;i++) dsq[i]=false;
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=m;j++)
        {
            dsq[i*i+j*j]=true;
        }
    }
    m=m*m*2;
    for (int i=0;i<=m;i++)
        if (dsq[i])
        {
                   len++;
                   num[len]=i;
        }
    for (int i=1;i<=len;i++)
    {
        for (int j=i+1;j<=len;j++)
        {
            if ((2-n)*num[i]+num[j]*(n-1)>m) break;
            bool okay=true;
            for (int k=1;k<=n-2;k++)
            {
                if (!dsq[num[j]+(num[j]-num[i])*k])
                {
                                    okay=false;
                                    break;
                                    }
            }
            if (okay) 
            {
                      rl++;
                      a[rl]=num[i];
                      b[rl]=num[j]-num[i];
                      }
        }
    }
    for (int i=1;i<=rl;i++)
    {
        for (int j=i+1;j<=rl;j++)
        {
            if ((b[i]>b[j])||((b[i]==b[j])&&(a[i]>a[j])))
            {
                                                         swap(a[i],a[j]);
                                                         swap(b[i],b[j]);
            }
        }
    }
    for (int i=1;i<=rl;i++)
        fout<<a[i]<<" "<<b[i]<<endl;
        
    if (rl==0) fout<<"NONE"<<endl;
    return 0;
}
