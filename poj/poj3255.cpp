#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define N 5010
#define M 200010
using namespace std;
struct edge
{
    int s, v, d, next;
}e[M];
int p[N], eid, n;
bool use[N];
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int d)
{
    e[eid].s = x;
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
struct node{
    int v, d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node(int a, int b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
void dijkstra(int begin, int d[N])
{
    memset(use, false, sizeof(use));
    for (int i = 1; i <= n; ++i) d[i] = INT_MAX / 2;
    while (!q.empty()) q.pop();
    d[begin] = 0;
    q.push(node(begin, 0));
    for (int i = 1; i <= n; ++i)
    {
        int v = q.top().v, s = q.top().d;
        while (use[v])
        {
            q.pop();
            v = q.top().v, s = q.top().d;
        }
        q.pop();
        use[v] = true;
        for (int j = p[v]; j != -1; j = e[j].next)
            if ((d[e[j].v] > s + e[j].d) && !use[e[j].v])
            {
                q.push(node(e[j].v, s + e[j].d));
                d[e[j].v] = s + e[j].d;
            }
    }
}
int d1[N], d2[N], lim, res, m;
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            insert2(x, y, d);
        }
        dijkstra(1, d1);
        dijkstra(n, d2);
        lim = d1[n]; res = INT_MAX;
        for (int i = 0; i < eid; ++i)
        {
            int temp = d1[e[i].s] + e[i].d + d2[e[i].v];
            if (temp > lim) res = min(res, temp);
        }
        printf("%d\n", res);
    }
    return 0;
}
