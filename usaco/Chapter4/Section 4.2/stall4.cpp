/*
ID:ybojan2
LANG:C++
TASK:stall4
*/
#include <fstream>
using namespace std;
ifstream cin("stall4.in");
ofstream cout("stall4.out");

int n,m,c[500][500],h[500],vh[500],flow,delta;
bool found;
void aug(int v)
{
     if (v==n){
               flow+=delta;
               found=true;
               return;
               }
     int i,temp=delta,minh=n-1;
     for (i=1;i<=n;i++)
         if (c[v][i]>0){
                        if (h[i]+1==h[v]){
                                          delta=min(delta,c[v][i]);
                                          aug(i);
                                          if (h[1]>=n) return;
                                          if (found) break;
                                          delta=temp;
                                          }
                        minh=min(minh,h[i]);
                        }
     if (found){
                c[v][i]-=delta;
                c[i][v]+=delta;
                }
     else{
          vh[h[v]]--;
          if (vh[h[v]]==0) h[1]=n;
          h[v]=minh+1;
          vh[h[v]]++;
          }
}
int main()
{
    memset(c,0,sizeof(c));
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int s,x;
        cin>>s;
        for (int j=1;j<=s;j++)
        {
            cin>>x;
            c[i+1][n+1+x]=1;
        }
    }
    for (int i=1;i<=n;i++) c[1][1+i]=1;
    for (int i=1;i<=m;i++) c[i+1+n][n+m+2]=1;
    n=n+m+2;
    vh[0]=n;
    flow=0;
    while (h[1]<n)
    {
          delta=2147483647;
          found=false;
          aug(1);
    }
    cout<<flow<<endl;
    return 0;
}
