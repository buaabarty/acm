/*
ID:ybojan2
LANG:C++
TASK:milk2
*/
#include <iostream>
#include <fstream>

using namespace std;

void swap (int &a,int &b)
{
     int tmp=a;
     a=b;
     b=tmp;
}

struct d
{
       int l,r;
}x[1000001];

void Quik_Sort(int l,int r)
{
     int i=l,j=r;
     int mid=x[(i+j)/2].l;
     for (;;)
     {
         for (;x[i].l<mid;i++){}
         for (;x[j].l>mid;j--){}
         if (i<=j)
         {
                  swap(x[i].l,x[j].l);
                  swap(x[i].r,x[j].r);
                  i++;
                  j--;
         }
         if (i>j) break;
     }
     if (l<j) Quik_Sort(l,j);
     if (i<r) Quik_Sort(i,r);
}

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    
    int n;
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>x[i].l>>x[i].r;
    }
    Quik_Sort(1,n);
    int left=x[1].l,right=x[1].r,res1=0,res2=0;
    for (int i=2;i<=n;i++)
    {
        if (x[i].l>right) 
        {
                          if (x[i].l-right>res2) res2=x[i].l-right;
                          if (right-left>res1) res1=right-left;
                          left=x[i].l;
                          right=x[i].r;
                          }
        else if (x[i].r>right) right=x[i].r;
    }
    if (right-left>res1) res1=right-left;
    fout<<res1<<" "<<res2<<endl;
    return 0;
}
