#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 100010
#define M 200010
using namespace std;
const int root = 1;
struct edge
{
    int v, d, next;
}e[M];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, int d)
{
    insert(x, y, d);
    insert(y, x, d);
}
int t[N], d[N], s[N], n;
bool vst[N];
void dfs(int v)
{
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            dfs(e[i].v);
            d[v] += d[e[i].v];
            s[v] += s[e[i].v] + d[e[i].v] * e[i].d;
        }
    d[v] += t[v];
    //printf("%d: %d %d\n", v, d[v], s[v]);
}
void dfs2(int v)
{
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            dfs(e[i].v);
        }
}
int main()
{
    while (~scanf("%d", &n))
    {
        mapinit();
        for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
        for (int i = 1; i < n; ++i)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            insert2(x, y, d);
        }
        memset(d, 0, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(vst, 0, sizeof(vst));
        dfs(root);
        int res = INT_MAX;
        memset(vst, 0, sizeof(vst));
        dfs2(root);
    }
    return 0;
}
