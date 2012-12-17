/*
ID:ybojan2
LANG:C++
TASK:barn1
*/

#include <iostream>
#include <fstream>

using namespace std;

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    
    int i,m,s,c,barn[201]={0},dp[201][201],last,sum=0,len=0,res[201];
    fin>>m>>s>>c;
    for (i=1;i<=c;i++)
    {
        int x;
        fin>>x;
        barn[x]=1;
    }
    sum=c;

    for (i=1;barn[i]==0;i++){}
    
    last=i;i++;
    for (;i<=s;i++)
    {
        if (barn[i]!=barn[i-1]) 
        {
                                if (barn[i]==1) 
                                {
                                                len++;
                                                res[len]=i-last;
                                }
                                last=i;
        }
    }
    
    for (i=1;i<=len;i++)
    {
        for (int j=i+1;j<=len;j++)
        {
            if (res[i]>res[j]) swap(res[i],res[j]);
        }
    }

    for (i=1;i<=len-m+1;i++)
    {
        sum+=res[i];
    }
    fout<<sum<<endl;
    return 0;
}
