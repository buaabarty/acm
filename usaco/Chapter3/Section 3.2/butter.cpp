/*
ID:ybojan2
LANG:C++
TASK:butter
*/

#include <iostream>
#include <fstream>

using namespace std;

struct edge{
       int x,y,d;
}e[3000];

int n,p,c,cnt[1000],d[1000],s[1000],t[1000],res=2147483647;

void sort(int l,int r)
{
     int i=l,j=r,mid=e[(i+j)/2].x;
     for (;;)
     {
         for (;e[i].x<mid;i++){}
         for (;e[j].x>mid;j--){}
         if (i<=j){
                   edge tmp=e[i];
                   e[i]=e[j];
                   e[j]=tmp;
                   i++;
                   j--;
                   }
         if (i>j) break;
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
}

void doit(int v)
{
     int q[10000],l=1,r=1,use[1000],now;
     memset(q,0,sizeof(q));
     memset(use,false,sizeof(use));
     for (int i=1;i<=n;i++)
         d[i]=1000000000;
     d[v]=0;
     q[1]=v;
     use[v]=true;
     for (;;)
     {
         now=q[l];
         for (int i=s[now];i<=t[now];i++)
         {
             if (d[now]+e[i].d<d[e[i].y]){
                                          d[e[i].y]=d[now]+e[i].d;
                                          if (!use[e[i].y]){
                                                            use[e[i].y]=true;
                                                            r++;
                                                            q[r]=e[i].y;
                                                            }
                                          }
         }
         use[q[l]]=false;
         l++;
         if (l>r) break;
     }
}

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    
    fin>>p>>n>>c;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=p;i++)
    {
        int x;
        fin>>x;
        cnt[x]++;
    }
    for (int i=1;i<=c;i++)
    {
        fin>>e[i].x>>e[i].y>>e[i].d;
        e[i+c]=e[i];
        int tmp=e[i].x;
        e[i].x=e[i].y;
        e[i].y=tmp;
    }
    c*=2;
    sort(1,c);
    for (int i=1;i<=c;i++)
    {
        if (e[i].x!=e[i-1].x) s[e[i].x]=i;
        if (e[i].x!=e[i+1].x) t[e[i].x]=i;
    }
    for (int i=1;i<=n;i++)
    {
        int sum=0;
        doit(i);
        for (int j=1;j<=n;j++)
            sum+=cnt[j]*d[j];
        if (sum<res) res=sum;
    }
    fout<<res<<endl;
    return 0;
}
