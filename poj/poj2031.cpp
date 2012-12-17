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
    double d;
}e[MAXM];
int p[MAXN], eid;
void insert(int x, int y, double d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
struct node
{
    int v;
    double d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node (int a, double b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
double d[MAXN];
bool use[MAXN];
int n;
double prim(int v)
{
    double s = 0;
    memset(d, 0x7f, sizeof(d));
    memset(use, false, sizeof(use));
    while (!q.empty()) q.pop();
    d[v] = 0;
    q.push(node(v, 0));
    for (int i = 1; i <= n; ++i)
    {
        int mv = q.top().v;
        double ms = q.top().d;
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
double x[MAXN], y[MAXN], z[MAXN], r[MAXN];
double dist(int a, int b)
{
    double dx = x[a] - x[b], dy = y[a] - y[b], dz = z[a] - z[b];
    return sqrt(dx * dx + dy * dy + dz * dz);
}
bool init()
{
    memset(p, -1, sizeof(p));
    eid = 0;
    scanf("%d", &n);
    if (!n) return false;
    for (int i = 1; i <= n; ++i) scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (dist(i, j) <= r[i] + r[j]){
                insert(i, j, 0);
                insert(j, i, 0);
            }
            else{
                insert(i, j, dist(i, j) - r[i] - r[j]);
                insert(j, i, dist(i, j) - r[i] - r[j]);
            }
    return true;
}
int main()
{
    while (init())
    {
        printf("%.3f\n", prim(1));
    }
    return 0;
}
