/*
ID:ybojan2
LANG:C++
TASK:transform
*/
#include <iostream>
#include <fstream>

using namespace std;

int a[11][11],b[11][11],tmp[11][11],n;

void turn()
{
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j<=n;j++)
         {
             tmp[j][n-i+1]=a[i][j];
         }
     }
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j<=n;j++)
         {
             a[i][j]=tmp[i][j];
         }
     }
}

void reverse()
{
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j<=n;j++)
         {
             tmp[i][n-j+1]=a[i][j];
         }
     }
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j<=n;j++)
         {
             a[i][j]=tmp[i][j];
         }
     }
}

bool same()
{
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j<=n;j++)
         {
             if (a[i][j]!=b[i][j]) return false;
         }
     }
     return true;
}

int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    fin>>n;
    for (int i=1;i<=n;i++)
    {
        char c;
        for (int j=1;j<=n;j++)
        {
            fin>>c;
            (c=='@')?a[i][j]=1:a[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        char c;
        for (int j=1;j<=n;j++)
        {
            fin>>c;
            (c=='@')?b[i][j]=1:b[i][j]=0;
        }
    }

    int res=7;
    for (int i=1;i<=2;i++)
    {
        reverse();
        for (int j=1;j<=4;j++)
        {
            turn();
            int now;
            if (same())
            {
                     if (i==1) {
                              if (j!=4) now=5;
                              else now=4;
                              }
                     else {
                          if (j!=4) now=j;
                          else now=6;
                          }
                     if (now<res) res=now;
            }
        }
    }
    fout<<res<<endl;
    return 0;
}
