#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 20010
#define MAXM 50010
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, m, dfn[MAXN], low[MAXN], stack[MAXN], belong[MAXN];
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
bool a[MAXN], b[MAXN];
int main()
{
    int x, y;
    while (~scanf("%d%d", &n, &m))
    {
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
        }
        solve();
        memset(a, true, sizeof(a));
        memset(b, true, sizeof(b));
        for (int i = 1; i <= n; ++i)
            for (int j = p[i]; j != -1; j = e[j].next)
                if (belong[i] != belong[e[j].v])
                {
                    a[belong[i]] = false;
                    b[belong[e[j].v]] = false;
                }
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= bcnt; ++i)
        {
            s1 += a[i];
            s2 += b[i];
        }
        if (bcnt == 1) printf("0\n");
        else printf("%d\n", max(s1, s2));
    }
    return 0;
}
