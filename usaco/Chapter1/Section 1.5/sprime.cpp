/*
ID:ybojan2
LANG:C++
TASK:sprime
*/

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <math.h>

using namespace std;

int num[10],n,len=0,res[1000000],maxn=0;

bool isprime(int x)
{
     if (x==1) return false;
     if (x==2) return true;
     for (int i=2;i<=sqrt(x);i++)
     {
         if (x%i==0) return false;
     }
     return true;
}

void get(int deep,int now)
{
     if (deep>maxn) maxn=deep;
     if (deep>n)
     {
                if (isprime(now)) {
                                  len++;
                                  res[len]=now;
                                  }
                return;
     }
     for (int i=1;i<=9;i+=2)
     {
         if (i==5) continue;
         if (!isprime(now*10+i)) continue;
         num[deep]=i;
         get(deep+1,now*10+i);
     }
}

int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    fin>>n;
    num[1]=2;
    get(2,2);
    num[1]=3;
    get(2,3);
    num[1]=5;
    get(2,5);
    num[1]=7;
    get(2,7);
    for (int i=1;i<=len;i++)
        fout<<res[i]<<endl;
    return 0;
}
