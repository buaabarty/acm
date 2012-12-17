#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
#define M 1000010
using namespace std;
struct edge
{
    int v, next;
}e[M];
int p[N], eid;
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
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
int rootcnt, root, n;
int dfn[N], low[N], dcnt;
bool cut[N];
void dfs(int v, int last)
{
    dfn[v] = low[v] = ++dcnt;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (!dfn[u])
        {
            if (v == root)
            {
                if (++rootcnt > 1) cut[v] = true;
            }
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if ((v != root) && (dfn[v] <= low[u])) cut[v] = true;
        }
        else if (u != last) low[v] = min(low[v], dfn[u]);
    }
}
int cutcnt()
{
    memset(cut, false, sizeof(cut));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    rootcnt = dcnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
        {
            rootcnt = 0;
            root = i;
            dfs(root, -1);
        }
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += cut[i];
    return sum;
}
int main()
{
    int x, y;
    while (scanf("%d", &n), n)
    {
        mapinit();
        scanf("%d", &x);
        while (x)
        {
            while (getchar() != '\n')
            {
                scanf("%d", &y);
                insert2(x, y);
            }
            scanf("%d", &x);
        }
        printf("%d\n", cutcnt());
    }
    return 0;
}
