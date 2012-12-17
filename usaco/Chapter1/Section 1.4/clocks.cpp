/*
ID:ybojan2
LANG:C++
TASK:clocks
*/

#include <iostream>
#include <fstream>

using namespace std;

int dat[10],now[10],len=99,res[100];

bool same()
{
     for (int i=1;i<=9;i++)
     {
         if (dat[i]!=now[i]) return false;
     }
     return true;
}

int main()
{
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");

    for (int i=1;i<=9;i++)
    {
        fin>>now[i];
        now[i]/=3;
        now[i]%=4;
    }
    for (int i=1;i<=9;i++)
        dat[i]=0;
    for (int i=1;i<=99;i++)
        res[i]=9;


    for (int i1=1;i1<=4;i1++)
    {
        now[1]=(now[1]+1)%4;
        now[2]=(now[2]+1)%4;
        now[4]=(now[4]+1)%4;
        now[5]=(now[5]+1)%4;
        for (int i2=1;i2<=4;i2++)
        {
            now[1]=(now[1]+1)%4;
            now[2]=(now[2]+1)%4;
            now[3]=(now[3]+1)%4;
            for (int i3=1;i3<=4;i3++)
            {
                now[2]=(now[2]+1)%4;
                now[3]=(now[3]+1)%4;
                now[5]=(now[5]+1)%4;
                now[6]=(now[6]+1)%4;
                for (int i4=1;i4<=4;i4++)
                {
                    now[1]=(now[1]+1)%4;
                    now[4]=(now[4]+1)%4;
                    now[7]=(now[7]+1)%4;
                    for (int i5=1;i5<=4;i5++)
                    {
                        now[2]=(now[2]+1)%4;
                        now[4]=(now[4]+1)%4;
                        now[5]=(now[5]+1)%4;
                        now[6]=(now[6]+1)%4;
                        now[8]=(now[8]+1)%4;
                        for (int i6=1;i6<=4;i6++)
                        {
                            now[3]=(now[3]+1)%4;
                            now[6]=(now[6]+1)%4;
                            now[9]=(now[9]+1)%4;
                            for (int i7=1;i7<=4;i7++)
                            {
                                now[4]=(now[4]+1)%4;
                                now[5]=(now[5]+1)%4;
                                now[7]=(now[7]+1)%4;
                                now[8]=(now[8]+1)%4;
                                for (int i8=1;i8<=4;i8++)
                                {
                                    now[7]=(now[7]+1)%4;
                                    now[8]=(now[8]+1)%4;
                                    now[9]=(now[9]+1)%4;
                                    for (int i9=1;i9<=4;i9++)
                                    {
                                        now[5]=(now[5]+1)%4;
                                        now[6]=(now[6]+1)%4;
                                        now[8]=(now[8]+1)%4;
                                        now[9]=(now[9]+1)%4;
                                        if (same())
                                        {
                                                   int tl=0,tt[100],i;
                                                   for (i=1;i<=i1%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=1;
                                                   }
                                                   for (i=1;i<=i2%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=2;
                                                   }
                                                   for (i=1;i<=i3%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=3;
                                                   }
                                                   for (i=1;i<=i4%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=4;
                                                   }
                                                   for (i=1;i<=i5%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=5;
                                                   }
                                                   for (i=1;i<=i6%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=6;
                                                   }
                                                   for (i=1;i<=i7%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=7;
                                                   }
                                                   for (i=1;i<=i8%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=8;
                                                   }
                                                   for (i=1;i<=i9%4;i++)
                                                   {
                                                       tl++;
                                                       tt[tl]=9;
                                                   }
                                                   if (tl>len) break;
                                                   if (tl<len)
                                                   {
                                                              len=tl;
                                                              for (i=1;i<=len;i++)
                                                                  res[i]=tt[i];
                                                              }
                                                   else
                                                   {
                                                       bool flag=true;
                                                       for (i=1;i<=len;i++)
                                                       {
                                                           if (res[i]!=tt[i])
                                                           {
                                                                             flag=(tt[i]<res[i]);
                                                                             break;
                                                                             }
                                                       }
                                                       if (flag)
                                                       {
                                                                 len=tl;
                                                                 for (i=1;i<=len;i++)
                                                                     res[i]=tt[i];
                                                                 }
                                                   }
                                                   }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    for (int i=1;i<len;i++)
        fout<<res[i]<<" ";
    fout<<res[len]<<endl;
    return 0;
}
