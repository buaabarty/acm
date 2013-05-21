#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100010
using namespace std;
struct edge
{
    int v, next;
}e[N*2];
int p[N], eid;
int n, k;
int f1[N][30], f2[N][30], c[N];
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0 ;
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
bool vst[N];
void dfs1(int v)
{
    vst[v] = 1;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (vst[u]) continue;
        dfs1(u);
        for (int j = 0; j < k; ++j)
            f1[v][j + 1] += f1[u][j];
    }
    f1[v][0] = c[v];
}
void dfs2(int v, int last)
{
    vst[v] = 1;
    if (last != -1)
    {
        for (int i = 0; i < k; ++i)
            f2[v][i + 1] += f2[last][i];
        for (int i = 1; i < k; ++i)
            f2[v][i + 1] -= f1[v][i - 1];
    }
    for (int i = 0; i <= k; ++i)
        f2[v][i] += f1[v][i];
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (vst[u]) continue;
        dfs2(u, v);
    }
}
int main()
{
    mapinit();
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert2(x, y);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    memset(vst, 0, sizeof(vst));
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    dfs1(1);
    memset(vst, 0, sizeof(vst));
    dfs2(1, -1);
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = 0; j <= k; ++j)
            sum += f2[i][j];
        printf("%d\n", sum);
    }
    return 0;
}
