/*
ID:ybojan2
LANG:C++
TASK:zerosum
*/

#include <iostream>
#include <fstream>

using namespace std;

int n,dat[10],res[1000][10],cnt=0;

void search(int sum,int last,int deep,int flag)
{
     if (deep==n+1)
     {
                   sum+=last*flag;
                   if (sum!=0) return ;
                   cnt++;
                   for (int i=2;i<=n;i++)
                       res[cnt][i]=dat[i];
                   return ;
     }
     dat[deep]=0;
     search(sum,last*10+deep,deep+1,flag);
     sum+=last*flag;
     dat[deep]=1;
     flag=1;
     search(sum,deep,deep+1,1);
     dat[deep]=2;
     flag=-1;
     search(sum,deep,deep+1,-1);
}

int main()
{
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");
    fin>>n;
    
    search(0,1,2,1);
    
    for (int i=1;i<=cnt;i++)
    {
                   fout<<1;
                   for (int j=2;j<=n;j++)
                   {
                       switch (res[i][j])
                       {
                              case 0:
                                   fout<<" ";
                                   break;
                              case 1:
                                   fout<<"+";
                                   break;
                              case 2:
                                   fout<<"-";
                                   break;
                       }
                       fout<<j;
                   }
                   fout<<endl;               
    }
    return 0;
}
