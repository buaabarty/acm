#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 256
#define MAXM 65536
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int n, p[MAXN], eid;
struct circle{
    int x, y, r;
}c[MAXN];
int sqr(int x)
{
    return x * x;
}
bool intersect(circle a, circle b)
{
    return (sqr(a.x - b.x) + sqr(a.y - b.y) <= sqr(a.r + b.r));
}
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void printmap()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d,", e[j].v);
        printf("\n");
    }
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int d[3][MAXN];
bool use[MAXN];
void dijkstra(int v, int s)
{
    memset(use, false, sizeof(use));
    for (int i = 1; i <= n; ++i) d[s][i] = INT_MAX / 4;
    d[s][v] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a, b = INT_MAX;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (d[s][j] < b))
            {
                b = d[s][j];
                a = j;
            }
        use[a] = true;
        for (int j = p[a]; j != -1; j = e[j].next)
            if (!use[e[j].v]) d[s][e[j].v] = min(d[s][e[j].v], b + 1);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        mapinit();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].r);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (intersect(c[i], c[j]))
                {
                    insert(i, j);
                    insert(j, i);
                }
//        printmap();
        for (int i = 1; i <= 3; ++i)
            dijkstra(i, i - 1);
        int res = INT_MAX;
        for (int i = 1; i <= n; ++i)
            res = min(res, d[0][i] + d[1][i] + d[2][i]);
        if (res >= n) printf("-1\n");
        else printf("%d\n", n - res - 1);
    }
    return 0;
}
