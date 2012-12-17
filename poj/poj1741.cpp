#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10010
#define M 20010
using namespace std;
int n, k;
struct data
{
    int r, d;
    data(int _r, int _d)
    {
        r = _r, d = _d;
    }
    data(){}
    bool operator < (const data a) const
    {
        return d < a.d;
    }
};
vector<data> d[N];
struct edge
{
    int v, d, next;
}e[M];
int p[N], eid, res;
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
bool vst[N];
void dfs(int v)
{
    bool leaf = true;
    d[v].clear();
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            leaf = false;
            int now = e[i].v;
            dfs(now);
            for (int j = 0, s = d[now].size(); j < s; ++j) d[v].push_back(data(d[now][j].r, d[now][j].d + e[i].d));
        }
    if (leaf)
    {
        d[v].push_back(node(v, 0));
        return;
    }
    sort(d[v].begin(), d[v].end());
    int s = d.size(), ;
    for (int i = 0, j = s; i < s; ++i)
    {
        while ((d[i] + d[j] > k) && (j >= i)) --j;
        if (i > j) break;
    }
}
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        mapinit();
        for (int i = 1; i < n; ++i)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            insert2(x, y, d);
        }
        memset(vst, 0, sizeof(vst)); res = 0;
        dfs(1);
    }
    return 0;
}
