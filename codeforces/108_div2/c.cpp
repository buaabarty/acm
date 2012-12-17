#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#define N 100010
#define M 1000010
using namespace std;
struct node
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
int n, m, x, y, d;
bool st[N], goo[N];
void go(int v)
{
    int d = INT_MAX;
    while (p[v] != -1)
    {
        d = min(d, e[p[v]].d);
        v = e[p[v]].v;
    }
    printf(" %d %d\n", v, d);
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(st, true, sizeof(st));
        memset(goo, false, sizeof(goo));
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &x, &y, &d);
            insert(x, y, d);
            st[y] = false;
            goo[x] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += (st[i] && goo[i]);
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i)
            if (st[i] && goo[i])
            {
                printf("%d", i);
                go(i);
            }
    }
    return 0;
}

