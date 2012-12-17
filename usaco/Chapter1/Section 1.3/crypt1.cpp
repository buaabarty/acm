/*
ID:ybojan2
LANG:C++
TASK:crypt1
*/

#include <iostream>
#include <fstream>

using namespace std;

bool dig[10];

bool ok(int x)
{
     for (;x>0;)
     {
         if (!dig[x%10]) return false;
         x/=10;
     }
     return true;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
    for (int i=0;i<=9;i++) dig[i]=false;
    
    int n,res=0;
    
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        fin>>x;
        dig[x]=true;
    }
    
    for (int a=1;a<=9;a++)
    {
        if (!dig[a]) continue;
        for (int b=1;b<=9;b++)
        {
            if (!dig[b]) continue;
            for (int c=1;c<=9;c++)
            {
                if (!dig[c]) continue;
                for (int d=1;d<=9;d++)
                {
                    if (!dig[d]) continue;
                    for (int e=1;e<=9;e++)
                    {
                        if (!dig[e]) continue;
                        int x=a*100+b*10+c,y=d*10+e,c1=x*e,c2=x*d,c3=c1+c2*10;
                        if ((ok(c1))&&(ok(c2))&&(ok(c3)))
                        {
                                                         if ((c1<=999)&&(c2<=999)&&(c3<=9999))
                                                         {
                                                                                              res++;
                                                         }
                        }
                    }
                }
            }
        }
    }
    
    fout<<res<<endl;
    return 0;
}
