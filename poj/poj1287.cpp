#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
struct edge
{
    int v, d, next;
}e[100000];
int p[64], dist[64], n, eid, m;
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
bool use[64];
int prim()
{
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= n; ++i) dist[i] = INT_MAX / 2;
    dist[1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a, b = INT_MAX;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (dist[j] < b))
            {
                b = dist[j];
                a = j;
            }
        use[a] = 1;
        ans += b;
        for (int j = p[a]; j != -1; j = e[j].next)
            if (!use[e[j].v] && (e[j].d < dist[e[j].v]))
            {
                dist[e[j].v] = e[j].d;
            }
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n), n)
    {
        scanf("%d", &m);
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            insert2(x, y, d);
        }
        printf("%d\n", prim());
    }
    return 0;
}
