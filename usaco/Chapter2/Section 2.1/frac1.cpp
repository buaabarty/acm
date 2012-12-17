/*
ID:ybojan2
LANG:C++
TASK:frac1
*/

#include <iostream>
#include <fstream>

using namespace std;

int n,a[100000],b[100000],len=0;


void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

int gcd(int x,int y)
{
    if (x>y) swap(x,y);
    if (x==0) return y;
    return (gcd(y%x,x));
}

void sort(int l,int r)
{
     int i=l,j=r;
     float mid=(float)a[(i+j)/2]/(float)b[(i+j)/2];
     for (;;)
     {
         for (;(float)a[i]/(float)b[i]<mid;i++) {}
         for (;(float)a[j]/(float)b[j]>mid;j--) {}
         if (i<=j)
         {
                  swap(a[i],a[j]);
                  swap(b[i],b[j]);
                  i++;
                  j--;
         }
         if (i>j) break;
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
}

int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    
    fin>>n;
    len++;
    a[len]=0;
    b[len]=1;
    len++;
    a[len]=1;
    b[len]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=i-1;j++)
        {
            if (gcd(i,j)==1)
            {
                            len++;
                            a[len]=j;
                            b[len]=i;
            }
        }
    }
    
    
    sort(1,len);  
    for (int i=1;i<=len;i++)
        fout<<a[i]<<"/"<<b[i]<<endl;
    return 0;
}
