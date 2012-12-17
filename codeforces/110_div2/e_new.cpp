#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge
{
    int v, d, next;
}e[M];
int p[N], eid;
void mapinit()
{
    eid = 0;
    memset(p, -1, sizeof(p));
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
int n, u, v, w, s1[N], s2[N];
bool okay(int x)
{
    if (x == 0) return false;
    while (x)
    {
        if ((x % 10 != 4) && (x % 10 != 7)) return false;
        x /= 10;
    }
    return true;
}
bool vst[N];
void dfs(int v)
{
    bool leaf = true;
    vst[v] = true;
    int s = 0;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            dfs(e[i].v);
            if (e[i].d) s1[v] += (s1[e[i].v] + s2[e[i].v]);
            else
            {
                s1[v] += s1[e[i].v];
                s2[v] += s2[e[i].v];
            }
            s += calc(s1[e[i].v]);
            leaf = false;
        }
    if (leaf)
    {
        s1[v] = 0;
        s2[v] = 1;
        return;
    }

}
int main()
{
    while (~scanf("%d", &n))
    {
        mapinit();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            insert2(u, v, okay(w));
        }
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(vst, false, sizeof(vst));
        dfs(1);
    }
    return 0;
}
