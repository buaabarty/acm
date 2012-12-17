/*
ID:ybojan2
LANG:C++
TASK:sort3
*/
#include <iostream>
#include <fstream>

using namespace std;

int n,num[1001],now[1001],res=0;

void swap(int &x,int &y)
{
     int tmp=x;
     x=y;
     y=tmp;
}

void sort(int l,int r)
{
     int i=l,j=r,mid=num[(i+j)/2];
     for (;;)
     {
         for (;num[i]<mid;i++) {}
         for (;num[j]>mid;j--) {}
         if (i<=j)
         {
                  swap(num[i],num[j]);
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
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    
    
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>num[i];
    
    for (int i=1;i<=n;i++)
        now[i]=num[i];
    sort(1,n);
    
    for (int i=1;i<=n;i++)
    {
        if (num[i]==now[i]) continue;
        for (int j=i+1;j<=n;j++)
        {
            if (num[j]==now[j]) continue;
            if ((now[i]==num[j])&&(num[i]==now[j])&&(num[i]!=num[j])) 
            {
                                                    swap(now[i],now[j]);
                                                    res++;
                                                    break;
            }
        }
    }
    
    for (;;)
    {
        bool find=false;
        for (int i=1;i<=n;i++)
        {
            if (num[i]==now[i]) continue;
            for (int j=i+1;j<=n;j++)
            {
                if (num[j]==now[j]) continue;
                for (int k=j+1;k<=n;k++)
                {
                    if (num[k]==now[k]) continue;
                    if ((now[i]!=now[j])&&(now[j]!=now[k])&&(num[k]!=num[i]))
                    {
                                                                             now[i]=num[i];
                                                                             now[j]=num[j];
                                                                             now[k]=num[k];
                                                                             res+=2;
                                                                             find=true;
                                                                             break;
                    }
                    if (find) break;
                }
                if (find) break;
            }
            if (find) break;
        }
        if (!find) break;
    }
    fout<<res<<endl;

    return 0;
}
