#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define MAXN 256
#define MAXM 65536
using namespace std;
struct edge{
    int v, next;
    int d;
}e[MAXM];
int p[MAXN], eid;
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
struct node
{
    int v;
    int d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node (int a, int b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
int d[MAXN];
bool use[MAXN];
int n, m;
int prim(int v)
{
    int s = 0;
    memset(d, 0x7f, sizeof(d));
    memset(use, false, sizeof(use));
    while (!q.empty()) q.pop();
    d[v] = 0;
    q.push(node(v, 0));
    for (int i = 1; i <= n; ++i)
    {
        int mv = q.top().v;
        int ms = q.top().d;
        while (use[mv])
        {
            q.pop();
            mv = q.top().v, ms = q.top().d;
        }
        s += ms;
        q.pop();
        use[mv] = true;
        for (int j = p[mv]; j != -1; j = e[j].next)
            if (d[e[j].v] > e[j].d && !use[e[j].v])
            {
                q.push(node(e[j].v, e[j].d));
                d[e[j].v] = e[j].d;
            }
    }
    return s;
}
bool init()
{
    int map[MAXN][MAXN], x, y;
    memset(p, -1, sizeof(p));
    eid = 0;
    if (scanf("%d", &n) == EOF) return false;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &map[i][j]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = 0;
        map[y][x] = 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            insert(i, j, map[i][j]);
            insert(j, i, map[i][j]);
        }
    return true;
}
int main()
{
    while (init())
    {
        printf("%d\n", prim(1));
    }
    return 0;
}
