#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1024
#define MAXM 32768
using namespace std;
struct edge{
    int v, d, next;
}e[MAXM];
int eid, p[MAXN];
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, color[MAXN], x, y, z, d[3][MAXN], m;
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[j].d);
        printf("\n");
    }
}

bool init()
{
    scanf("%d", &n);
    if (!n) return false;
    scanf("%d", &m);
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    eid = 0;
    while (m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
        insert(y, x, z);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &color[i]);
//    print_map();
    return true;
}
int use[MAXN];
void dijkstra(int v, int c)
{
    for (int i = 1; i <= n; ++i) d[c][i] = INT_MAX / 3;
    memset(use, false, sizeof(use));
    d[c][v] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a = INT_MAX, b = 0;
        for (int j = 1; j <= n; ++j)
            if ((color[j] == c) && (d[c][j] < a) && (!use[j])){
                a = d[c][j];
                b = j;
            }
        if (!b) break;
        use[b] = true;
        for (int j = p[b]; j != -1; j = e[j].next)
            if (!use[e[j].v] && (color[e[j].v] == c) && (a + e[j].d < d[c][e[j].v]))
                d[c][e[j].v] = a + e[j].d;
    }
}
int main()
{
    while (init())
    {
        int res = INT_MAX;
        dijkstra(1, 1);
        dijkstra(2, 2);
        for (int i = 1; i <= n; ++i)
            if (color[i] == 1){
                for (int j = p[i]; j != -1; j = e[j].next)
                    if (color[e[j].v] == 2)
                        res = min(res, d[1][i] + d[2][e[j].v] + e[j].d);
            }
        if (res <= 10000000) printf("%d\n", res);
        else printf("-1\n");
    }
    return 0;
}
