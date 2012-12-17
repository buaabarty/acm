/*
ID:ybojan2
LANG:C++
TASK:milk
*/

#include <iostream>
#include <fstream>

using namespace std;

int p[5001]={0},a[5001]={0};

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

void qsort(int l,int r)
{
     int i=l,j=r,mid=p[(i+j)/2];
     for (;;)
     {
         for (;p[i]<mid;i++) {}
         for (;p[j]>mid;j--) {}
         if (i<=j)
         {
                  swap(p[i],p[j]);
                  swap(a[i],a[j]);
                  i++;
                  j--;
         }
         if (i>j) break;
     }
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
}

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    
    int n,m,sum=0;
    
    fin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        fin>>p[i]>>a[i];
    }
    
    qsort(1,m);
    
    for (int i=1;i<=m;i++)
    {
        if (n>=a[i])
        {
                    n-=a[i];
                    sum+=(p[i]*a[i]);
        }
        else {
             sum+=(p[i]*n);
             break;
             }
    }
    fout<<sum<<endl;
    return 0;
}
