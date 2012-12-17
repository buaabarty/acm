#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define N 30010
#define M 1000010
using namespace std;
struct edge
{
    int s, v, next;
}e[M], e2[M];
int p[N], eid, p2[N], eid2;
int dat[N], n, m, s[N], dp[N];
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].s = x;
    e[eid].v  = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void mapinit2()
{
    memset(p2, -1, sizeof(p2));
    eid2 = 0;
}
void insert2(int x, int y)
{
    e2[eid2].s = x;
    e2[eid2].v  = y;
    e2[eid2].next = p2[x];
    p2[x] = eid2++;
}
int dfn[N], low[N], stack[N], belong[N];
int bcnt, dindex = 0, top = 0;
bool instack[N];
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
void dfs(int v)
{
    int mm = 0;
    for (int i = p2[v]; i != -1; i = e2[i].next)
    {
        if (dp[e2[i].v] == -1) dfs(e2[i].v);
        mm = max(mm, dp[e2[i].v]);
    }
    dp[v] = mm + s[v];
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i) scanf("%d", &dat[i]);
        for (int i = 1; i <= n; ++i) dat[i] = max(dat[i], 0);
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ++x, ++y;
            insert(x, y);
        }
        solve();
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i)
            s[belong[i]] += dat[i];
        mapinit2();
        for (int i = 0; i < eid; ++i)
            if (belong[e[i].s] != belong[e[i].v]) insert2(belong[e[i].s], belong[e[i].v]);
        n = bcnt;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            if (dp[i] == -1) dfs(i);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = max(res, dp[i]);
        printf("%d\n", res);
    }
    return 0;
}
