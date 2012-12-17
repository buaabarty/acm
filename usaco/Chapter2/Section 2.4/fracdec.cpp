/*
ID:ybojan2
LANG:C++
TASK:fracdec
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int gcd(int x,int y)
{
    if (x==0) return y;
    return gcd(y%x,x);
}

int main()
{
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    
    int n,d,k[100001],dat[100001],len=0;
    fin>>n>>d;
    fout<<n/d<<".";
    if (n>=d) len=int(log(n/d)/log(10)+2.00001);
    else len=2;
    
    n%=d;
    memset(k,0,sizeof(k));
    int tmp=d/gcd(n,d);
    while (tmp%2==0) tmp/=2;
    while (tmp%5==0) tmp/=5;
    
    if (tmp==1)
    {
               for (;;)
               {
                   n*=10;
                   fout<<n/d;
                   n%=d;
                   if (n==0) break;
               }
               fout<<endl;
               return 0;
    }
    
    
    for (int i=1;;i++)
    {
        if (k[n]!=0)
        {
                    for (int j=1;j<=k[n]-1;j++)
                    {
                        fout<<dat[j];
                        len++;
                        if (len%76==0) fout<<endl;
                    }
                    fout<<"(";
                    len++;
                    if (len%76==0) fout<<endl;
                    for (int j=k[n];j<=i-1;j++)
                    {
                        fout<<dat[j];
                        len++;
                        if (len%76==0) fout<<endl;
                    }
                    fout<<")"<<endl;
                    return 0;
        }
        k[n]=i;
        n*=10;
        dat[i]=n/d;
        n%=d;
    }
    return 0;
}
