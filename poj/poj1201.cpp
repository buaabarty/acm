#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 65536
#define MAXM 1310720
#define MAXS 50000
using namespace std;
typedef struct edge{
    int v, d, next;
}EDGE;
EDGE e[MAXM];
int p[MAXN], eid, st, ed, n;
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool init()
{
    if (scanf("%d", &n) == EOF) return false;
    memset(p, -1, sizeof(p));
    eid = 0;
    int x, y, d, maxd = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &x, &y, &d);
        insert(x - 1, y, d);
        maxd = max(max(x - 1, y), maxd);
    }
    st = maxd + 1;
    ed = maxd + 2;
    for (int i = 0; i <= maxd; ++i)
        insert(st, i, 0);
    for (int i = 0; i <= maxd; ++i)
        insert(i, ed, 0);
    for (int i = 0; i < maxd; ++i)
        insert(i, i + 1, 0);
    for (int i = 1; i <= maxd; ++i)
        insert(i, i - 1, -1);
    n = ed;
    return true;
}

bool inq[MAXN];
queue<int> q;
int d[MAXN];
void spfa(int v)
{
    memset(d, 0x80, sizeof(d));
    inq[v] = true;
    q.push(v);
    d[v] = 0;
    while (!q.empty())
    {
        int x = q.front();
        for (int i = p[x]; i != -1; i = e[i].next)
            if (d[x] + e[i].d > d[e[i].v])
            {
                d[e[i].v] = d[x] + e[i].d;
                if (!inq[e[i].v])
                {
                    inq[e[i].v] = false;
                    q.push(e[i].v);
                }
            }
        q.pop(); inq[x] = false;
    }
}

int main()
{
    while (init())
    {
        spfa(st);
        printf("%d\n", d[ed]);
    }
    return 0;
}
