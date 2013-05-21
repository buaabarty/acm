#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 300010;

struct edge {
    int v, next;
}e[MAXN*10];

int p[MAXN], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}

int x[MAXN], y[MAXN];
int n, m;
int dfn[MAXN], low[MAXN], stack[MAXN], belong[MAXN];
int bcnt, dindex = 0, top = 0;
bool instack[MAXN];
void tarjan(int v)
{
    instack[v] = true;
    stack[++top] = v;
    dfn[v] = low[v] = ++dindex;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        if (!dfn[e[i].v])
        {
            tarjan(e[i].v);
            low[v] = min(low[v], low[e[i].v]);
        }
        else if (instack[e[i].v])
        {
            low[v] = min(low[v], dfn[e[i].v]);
        }
    }
    int temp;
    if (dfn[v] == low[v])
    {
        bcnt++;
        do{
            temp = stack[top--];
            instack[temp] = false;
            belong[temp] = bcnt;
        }while (temp != v);
    }
}
void solve()
{
    memset(dfn, 0, sizeof(dfn));
    top = bcnt = dindex = 0;
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
}

//---------------------拓扑排序求解
int cf[N], indeg[N], que[N], col[N];   //indeg[]为入度 ,que[]为队列,col[]为是否选择标志
bool ans[N];    //1表示选择，0表示不选择
bool sovle(int n)
{
     int i;
     index = tuan = top = 0;
     memset(dfn,0,sizeof(dfn));
     for (i = 0; i < 2*n; i++)
          if (!dfn[i]) tarjan(i);
     for (i = 0; i < n; i++)
     {
          if (belong[i] == belong[i+n]) //若有同一组的分量在同一个强连通分量中，则直接返回false
                return false;
          cf[belong[i]] = belong[i+n];  //存储同一组的分量所在哪个强连通分量，这样访问过其中一个后，另一个就不用再去访问了
          cf[belong[i+n]] = belong[i];  //在缩点的图中标记互斥的缩点。（原来互斥，现在也互斥）
     }
     memset(indeg,0,sizeof(indeg));
     memset(col,0,sizeof(col));
     memset(pn2,0xff,sizeof(pn2));
     cnt2 = 1;
     for (i = 1; i < cnt; i++)   //cnt条边,建立缩点图
          if (belong[e[i].from] != belong[e[i].to])
          {
           addedge2(belong[e[i].to],belong[e[i].from]);  //反向,是因为u--->v，如果选择了u，必须选择v，则应该反向，求入度为0的缩点
           indeg[belong[e[i].from]]++;     //统计入度
          }
     //-----------------开始拓扑排序
     int head = 1 ,tail = 1;
     for (i = 1; i <= tuan; i++)
     {
          if (indeg[i] == 0)  //入度为0入队列
                que[tail++] = i;
     }
     int v;
     while (head < tail)
     {
          int u = que[head];
          head++;
          if (col[u] == 0)    //对于未着色的点x，将x染成红色1，同时将与x矛盾的点cf[x]染成蓝色-1。
          {
               col[u] = 1;
               col[cf[u]] = -1;
          }
          for (i = pn2[u]; i != -1; i = e2[i].next)
          {
               v = e2[i].to;
               if (--indeg[v] == 0)    //入度为0
               {
                    que[tail++] = v;         //入队列
               }
          }
     }
     memset(ans,0,sizeof(ans));
     for (i = 0; i < n; i++)
     {
          if (col[belong[i]] == 1)
          {
                ans[i] = 1;
          }
     }
     return true;
}
int opp(int x)
{
    if (x < n) return x + n;
    else return x - n;
}


vector<int> se[MAXN*10];
struct ww {
    int x, y;
} dt[MAXN*10];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &dt[i].x, &dt[i].y);
        e[dt[i].x].push_back(i);
        e[dt[i].y].push_back(i);
    }
    init();
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < e[i].size(); ++j)
            for (int k = 0; k < e[i].size(); ++k)
                insert(e[i][j], e[i][k]);
    return 0;
}
