#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int N=110010;
const int M=30000005;//边集注意开双倍!!
const int inf=1<<27;
#define eps 1e-6
int head[N],point[M],next[M],flow[M],capa[M];
int dist[N],Q[N],work[N];
int nv,ne,source,sink;//点集,边集,源点,汇点
int min(int a,int b){return a>b?b:a;}
void InitNetwork(int _n,int _s,int _t)
{
 source=_s;sink=_t;
 nv=_n;ne=0;
 for(int i=0;i<nv;i++) head[i]=-1;
}
void AddEdge(int u,int v,int c1,int c2=0)
{
 point[ne]=v,capa[ne]=c1,flow[ne]=0,next[ne]=head[u],head[u]=(ne++);
 point[ne]=u,capa[ne]=c2,flow[ne]=0,next[ne]=head[v],head[v]=(ne++);//反向弧
 //printf("%d->%d  c%d\n",u,v,c1);
}
bool BFS_Dinic()
{
 memset(dist,255,sizeof(dist));
 dist[source]=0;
 int sizeQ=0;
 Q[sizeQ++]=source;
 for(int cl=0 ;cl<sizeQ ;cl++)
 {
  for(int k=Q[cl],i=head[k] ;i>=0 ;i=next[i])
   if(flow[i]<capa[i] && dist[point[i]]<0)
   {
    dist[point[i]]=dist[k]+1;
    Q[sizeQ++]=point[i];
   }
 }
 return dist[sink]>=0;
}
int DFS_Dinic(int x,int exp)
{
 if(x==sink) return exp;
 for(int &i=work[x] ;i>=0 ;i=next[i])
 {
  int v=point[i],tmp;
  if(flow[i]<capa[i] && dist[v]==dist[x]+1 && (tmp=DFS_Dinic(v,min(exp,capa[i]-flow[i])))>0)
  {
   flow[i]+=tmp;
   flow[i^1]-=tmp;
   return tmp;
  }
 }
 return 0;
}
int Dinic()
{
 int maxflow=0;
 while(BFS_Dinic())
 {
  for(int i=0;i<nv;i++) work[i]=head[i];
  while(1)
  {
   int delta=DFS_Dinic(source,inf);
   if(delta==0) break;
   maxflow+=delta;
  }
 }
 return maxflow;
}
int x, y, d;
int main()
{
    scanf("%d%d", &n, &m);
    int s = n + m + 1, t = n + m + 2;
    InitNetwork(n, s, t);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        Addedge(i, t, x);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("");
    }
    return 0;
}
