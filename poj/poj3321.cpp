#include <iostream>
#include <cstdio>
#include <cstring>
#define N 200010
using namespace std;
struct edge
{
    int v, next;
}e[N];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void mapinsert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    mapinsert(x, y);
    mapinsert(y, x);
}
int n, c[N], has[N], x, y, root, m;
char str[2];
int cnt = 0, st[N], ed[N];
bool vst[N];
void dfs(int v)
{
    vst[v] = true;
    st[v] = ++cnt;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) dfs(e[i].v);
    ed[v] = ++cnt;
}
int lowbit(int x)
{
    return x & (-x);
}
void insert(int k, int delta)
{
    while (k <= cnt)
    {
        c[k] += delta;
        k += lowbit(k);
    }
}
int getsum(int k)
{
    int s = 0;
    while (k > 0)
    {
        s += c[k];
        k -= lowbit(k);
    }
    return s;
}
int main()
{
    while (~scanf("%d", &n))
    {
        mapinit();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        for (int i = 1; i <= n; ++i) has[i] = 1;
        cnt = 0;
        memset(vst, false, sizeof(vst));
        dfs(1);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
            if (has[i])
            {
                insert(st[i], 1);
                insert(ed[i], 1);
            }
        scanf("%d", &m);
        while (m--)
        {
            scanf("%s%d", str, &x);
            if (str[0] == 'Q') printf("%d\n", (getsum(ed[x]) - getsum(st[x] - 1)) / 2);
            else
            {
                if (has[x])
                {
                    has[x] = 0;
                    insert(st[x], -1);
                    insert(ed[x], -1);
                }
                else
                {
                    has[x] = 1;
                    insert(st[x], 1);
                    insert(ed[x], 1);
                }
            }
        }
    }
    return 0;
}
