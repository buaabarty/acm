#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define MAXN 32768
#define MAXM 262144
using namespace std;
int n, m;
typedef struct edge{
    int v, d, next;
}EDGE;
EDGE e[MAXM];
int p[MAXN], eid, d[MAXN];
bool use[MAXN];
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    memset(p, -1, sizeof(p));
    memset(e, 0, sizeof(e));
    eid = 0;
    int a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, c);
    }
    return true;
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
void dijkstra(int v)
{
    memset(use, false, sizeof(use));
    memset(d, 0x7f, sizeof(d));
    while (!q.empty()) q.pop();
    d[0] = 0;
    q.push(node(v, 0));
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
            if (d[e[j].v] > s + e[j].d && !use[e[j].v])
            {
                q.push(node(e[j].v, s + e[j].d));
                d[e[j].v] = s + e[j].d;
            }
    }
}
int main()
{
    while (init())
    {
        dijkstra(1);
        cout << d[n] << endl;
    }
    return 0;
}
