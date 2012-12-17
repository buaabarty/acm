/*
ID:ybojan2
LANG:C++
TASK:rect1
*/

#include <iostream>
#include <fstream>

using namespace std;

int a,b,n,color[2502],cnt[2502],x1[2502],y1[2502],x2[2502],y2[2502];
     
int max(int x,int y)
{
    return (x>y)?x:y;
}

int min(int x,int y)
{
    return (x<y)?x:y;
}
     
void put(int xs,int ys,int xt,int yt,int d,int c)
{
     while (((xs>=x2[d])||(xt<=x1[d])||(ys>=y2[d])||(yt<=y1[d]))&&(d<=n)) d++;
     if (d==n+1){
                 cnt[c]+=(yt-ys)*(xt-xs);
                 return ;
                 }
     if (xs<x1[d]) {
                   put(xs,ys,x1[d],yt,d+1,c);
                   xs=x1[d];
                   }
     if (xt>x2[d]) {
                   put(x2[d],ys,xt,yt,d+1,c);
                   xt=x2[d];
                   }
     if (ys<y1[d]) put(xs,ys,xt,y1[d],d+1,c);
     if (yt>y2[d]) put(xs,y2[d],xt,yt,d+1,c);
}

int main()
{
    ifstream fin("rect1.in");
    ofstream fout("rect1.out");
    fin>>a>>b>>n;
    memset(cnt,0,sizeof(cnt));
    color[1]=1;
    x1[1]=0;
    y1[1]=0;
    x2[1]=a;
    y2[1]=b;
    n++;
    for (int i=2;i<=n;i++)
        fin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];
    for (int i=n;i>=1;i--)
        put(x1[i],y1[i],x2[i],y2[i],i+1,color[i]);
    for (int i=1;i<=2500;i++)
        if (cnt[i]!=0) fout<<i<<" "<<cnt[i]<<endl;
    return 0;
}
