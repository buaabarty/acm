/*
ID:ybojan2
LANG:C++
TASK:checker
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int full,res=0,num[20],n,dat[4][20],now;

void search(int a,int x,int y)
{
     if (a==full)
     {
                 res++;
                 return;
                 }
     int could=(~(a|x|y))&full,k;
     for (;could>0;)
     {
         k=could&(-could);
         could-=k;
         search(a+k,(x+k)<<1,(y+k)>>1);
     }
}

void search3(int a,int x,int y,int deep)
{
     if (now>=3) return ;
     if (a==full)
     {
                 now++;
                 for (int i=1;i<=n;i++)
                     dat[now][i]=num[i];
                 return;
     }
     int could=(~(a|x|y))&full,k;
     for (;could>0;)
     {
         if (now>=3) return;
         k=could&(-could);
         could-=k;
         num[deep]=int(log(k)/log(2)+1e-6)+1;
         search3(a+k,(x+k)<<1,(y+k)>>1,deep+1);
     }
}


int main()
{
    ifstream fin("checker.in");
    ofstream fout("checker.out");
    
    fin>>n;
    full=(1<<n)-1;
    search(0,0,0);
    search3(0,0,0,1);
    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<n;j++)
            fout<<dat[i][j]<<" ";
        fout<<dat[i][n]<<endl;
    }        
    fout<<res<<endl;
    return 0;
}
