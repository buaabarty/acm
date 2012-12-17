#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 40010
#define MAXL 16
using namespace std;
struct edge{
    int v, next;
}e[MAXN];
int eid, p[MAXN], root;
bool isroot[MAXN];
void mapinit()
{
    eid = 0;
    memset(p, -1, sizeof(p));
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
struct ST
{
    int dat, loc;
    ST(int x, int y)
    {
        dat = x, loc = y;
    }
    ST(){}
}st[MAXN][MAXL];
int n, num[MAXN], p2[MAXL], h[MAXN], firstapp[MAXN];
void Format_ST()
{
    memset(st, 0, sizeof(st));
    p2[0] = 1;
    for (int i = 1; i < MAXL; ++i) p2[i] = p2[i - 1] * 2;
    for (int i = 1; i <= n; ++i) st[i][0] = ST(h[i], num[i]);
    for (int j = 1, p = 1; j < MAXL; ++j, p *= 2)
        for (int i = 1; i <= n - p * 2 + 1; ++i)
            if (st[i][j - 1].dat > st[i + p][j - 1].dat) st[i][j] = st[i][j - 1];
            else st[i][j] = st[i + p][j - 1];
}
ST RMQ(int s, int t)
{
    int l = (int)(log((double)(t - s + 1)) / log(2.0) + 1e-6);
    if (st[s][l].dat > st[t - p2[l] + 1][l].dat) return st[s][l];
    else return st[t - p2[l] + 1][l];
}
void make(int v, int deep)
{
    h[++n] = -deep;
    num[n] = v;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        make(e[i].v, deep + 1);
        h[++n] = -deep;
        num[n] = v;
    }
}
int cnt[MAXN];
int main()
{
    int t, x, y, k;
    while (~scanf("%d", &n))
    {
        mapinit();
        memset(isroot, true, sizeof(isroot));
        memset(firstapp, 0, sizeof(firstapp));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            while (getchar() != '(');
            scanf("%d", &k);
            while (getchar() != ')');
            while (k--)
            {
                scanf("%d", &y);
                insert(x, y);
                isroot[y] = false;
            }
        }
        for (int i = 1; i <= n; ++i)
            if (isroot[i])
            {
                root = i;
                break;
            }
        n = 0;
        make(root, 0);
        for (int i = 1; i <= n; ++i)
            if (!firstapp[num[i]]) firstapp[num[i]] = i;
        Format_ST();
        scanf("%d\n", &k);
        memset(cnt, 0, sizeof(cnt));
        while (k--)
        {
            while (getchar() != '(');
            scanf("%d%d", &x, &y);
            while (getchar() != ')');
            int sx = firstapp[x], sy = firstapp[y];
            if (sx > sy) swap(sx, sy);
            cnt[RMQ(sx, sy).loc]++;
        }
        for (int i = 1; i <= n; ++i)
            if (cnt[i]) printf("%d:%d\n", i, cnt[i]);
    }
    return 0;
}
