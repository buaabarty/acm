#include <iostream>
#include <cstdio>
#include <cstring>
#define N 32
#define M 1024
using namespace std;
struct edge
{
    int v, d, next;
}e[M];
int p[N], eid, n, a[N], b[N];
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
double dat[N][N];
double dist[N];
bool vst[N];
bool instack[N];
bool DFS_SPFA(int v)
{
    vst[v] = true;
    instack[v] = true;
    bool res = false;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (dist[v] + e[i].d > dist[e[i].v])
        {
            dist[e[i].v] = dist[v] + e[i].d;
            if (!instack[e[i].v])
            {
                if (DFS_SPFA(e[i].v)) res = true;
            }
            else res = true;
            if (res) break;
        }
    instack[v] = false;
    return res;
}
bool HasCircle(int sum)
{
    memset(dist, 0x80, sizeof(dist));
    memset(instack, false, sizeof(instack));
    memset(vst, false, sizeof(vst));
    dist[0] = 0;
    return DFS_SPFA(0) && (dist[24] == sum);
}
void print_map()
{
    for (int i = 0; i <= 24; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[j].d);
        printf("\n");
    }
}
bool okay(int limit)
{
    mapinit();
    for (int i = 1; i <= n; ++i)
        insert(i, i - 1, -b[i]);
    for (int i = 9; i <= n; ++i)
        insert(i - 8, i, a[i]);
    for (int i = 0; i < n; ++i)
        insert(i, i + 1, 0);
    for (int i = 1; i <= 8; ++i)
        insert(i + 16, i, a[i] - limit);
    insert(0, 24, limit);
    //print_map();
    return !HasCircle(limit);
}
int main()
{
    int T, m, x, left, right;
    scanf("%d", &T);
    while (T--)
    {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= 24; ++i)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        left = 0, right = m;
        while (m--)
        {
            scanf("%d", &x);
            b[++x]++;
        }
        n = 24;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (!okay(left)) left = right;
                break;
            }
            if (okay((left + right) / 2)) right = (left + right) / 2;
            else left = (left + right) / 2 + 1;
        }
        if (okay(left)) printf("%d\n", left);
        else printf("No Solution\n");
    }
    return 0;
}
