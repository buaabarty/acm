/*
ID:ybojan2
LANG:C++
TASK:contact
*/

#include <iostream>
#include <fstream>

using namespace std;

struct data{
       int d,l,x;
}res[100001];

void swap(data &x,data &y)
{
     data tmp=x;
     x=y;
     y=tmp;
}

int main()
{
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    
    int a,b,n,app[13][4096],dat[200001],len,od;
    
    fin>>a>>b>>n;
    od=n;
    n*=100;
    memset(app,0,sizeof(app));
    for (int i=1;i<=n;i++)
    {
        res[i].d=0;
        res[i].l=100;
        res[i].x=4095;
    }
    for (len=1;!fin.eof();len++)
    {
        char c;
        fin>>c;
        dat[len]=c-'0';
    }
    len-=2;
    
    for (int i=a;i<=b;i++)
    {
        if (i>len) break;
        int now=0;
        for (int j=1;j<=i;j++)
            now=now*2+dat[j];
        app[i][now]++;
        for (int j=i+1;j<=len;j++)
        {
            now=now*2+dat[j];
            now%=(1<<i);
            app[i][now]++;
        }
        for (int j=0;j<=(1<<i)-1;j++)
            if (app[i][j]>res[n].d){
                                res[n].d=app[i][j];
                                res[n].l=i;
                                res[n].x=j;
                                for (int k=n;(k>1)&&(res[k].d>res[k-1].d);k--) swap(res[k],res[k-1]);
                                }
    }
    
    
    
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if ((res[i].d==res[j].d)){
                                      if (res[i].l>res[j].l) swap(res[i],res[j]);
                                      else if (res[i].l==res[j].l)
                                      {
                                           if (res[i].x>res[j].x) swap(res[i],res[j]);
                                      }
            else break;
            }
    int count=0,st=0;
    for (int i=1;i<=n;i++)
    {
        if (res[i].d!=res[i-1].d) {
                                  count++;
                                  if ((count>od)||(res[i].d==0)) break;
                                  if (i!=1) fout<<endl;
                                  fout<<res[i].d<<endl;
                                  st=0;
                                  }
        else 
        {
             if (st%6!=0)  fout<<" ";
             else if (st!=0) fout<<endl;
        }
        st++;
        for (int j=res[i].l-1;j>=0;j--)
        {
            fout<<res[i].x/(1<<j);
            res[i].x%=(1<<j);
        }        
    }
    fout<<endl;
    return 0;
}
