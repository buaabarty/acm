#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#define MAXN 65536
#define MAXM 6553600
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
        scanf("%d%d", &x, &y);
        insert(x, y + 1, 2);
        maxd = max(maxd, y + 1);
    }
    //printf("%d\n", st);
    for (int i = 0; i < maxd; ++i)
        insert(i, i + 1, 0);
    for (int i = 0; i < maxd; ++i)
        insert(i + 1, i, -1);
    n = maxd;
    return true;
}
bool inq[MAXN];
queue<int> q;
int d[MAXN];
void spfa(int v)
{
    memset(d, 0x80, sizeof(d));
    memset(inq, false, sizeof(inq));
    inq[v] = true;
    while (!q.empty()) q.pop();
    q.push(v);
    d[v] = 0;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
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
        inq[x] = false;
    }
}
int main()
{
    while (init())
    {
        spfa(0);
        printf("%d\n", d[n]);
    }
    return 0;
}
