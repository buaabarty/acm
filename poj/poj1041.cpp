#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define M 1000010
using namespace std;
struct edge
{
    int v, d, next;
    bool f;
}e[M];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int z)
{
    e[eid].v = y;
    e[eid].d = z;
    e[eid].f = true;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, int z)
{
    insert(x, y, z);
    insert(y, x, z);
}
int res[M], len;
void dfs(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
        if (e[i].f)
        {
            e[i].f = e[i ^ 1].f = false;
            dfs(e[i].v);
            res[++len] = e[i].d;
        }
}
int d[N], n, m, st;
struct data
{
    int x, y, z;
}dat[M];
bool cmp(data a, data b)
{
    return a.z > b.z;
}
int main()
{
    int x, y, z;
    while (scanf("%d%d", &x, &y), (x + y))
    {
        mapinit();
        memset(d, 0, sizeof(d));
        len = n = m = 0;
        st = min(x, y);
        do
        {
            m++;
            scanf("%d", &z);
            dat[m].x = x;
            dat[m].y = y;
            dat[m].z = z;
            d[x]++, d[y]++;
            n = max(n, max(x, y));
        }while (scanf("%d%d", &x, &y), (x + y));
        sort(dat + 1, dat + m + 1, cmp);
        for (int i = 1; i <= m; ++i)
            insert2(dat[i].x, dat[i].y, dat[i].z);
        bool flag = true;
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= n; ++i)
            if (d[i] & 1)
            {
                flag = false;
                break;
            }
        if (!flag) puts("Round trip does not exist.");
        else
        {
            dfs(st);
            if (len != m) puts("Round trip does not exist.");
            else
            {
                for (int i = len; i > 1; --i)
                    printf("%d ", res[i]);
                printf("%d\n", res[1]);
            }
        }
    }
    return 0;
}
