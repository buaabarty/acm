#include <queue>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXM 524288
#define MAXN 512
using namespace std;
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
struct EDGE
{
    int v, next;
    double d;
}e[MAXM];
int eid, p[MAXN];
void insert(int x, int y, double d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
double d[MAXN];
bool use[MAXN];
double sqr(double x)
{
    return x * x;
}
double dist(double xa, double ya, double xb, double yb)
{
    return sqrt(sqr(xa - xb) + sqr(ya - yb));
}
int k, n;
void prim(int v)
{
    memset(d, 0x7f, sizeof(d));
    memset(use, false, sizeof(use));
    while (!q.empty()) q.pop();
    d[v] = 0;
    q.push(node(v, 0));
    for (int i = 1; i <= n; ++i)
    {

        int mv = q.top().v, ms = q.top().d;
        while (use[mv])
        {
            q.pop();
            mv = q.top().v, ms = q.top().d;
        }
        q.pop();
        use[mv] = true;
//        printf("%d ", i);
        for (int j = p[mv]; j != -1; j = e[j].next)
            if (d[e[j].v] > e[j].d && !use[e[j].v])
            {
                q.push(node(e[j].v, e[j].d));
                d[e[j].v] = e[j].d;
            }
    }
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: ");
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%.2f) ", e[j].v, e[j].d);
        printf("\n");
    }
}
void sort(int l, int r)
{
    int i = l, j = r;
    double mid = d[(i + j) / 2];
    do{
        while (d[i] < mid) ++i;
        while (d[j] > mid) --j;
        if (i <= j)
        {
            swap(d[i], d[j]);
            ++i; --j;
        }
    }while (i <= j);
    if (l < j) sort(l, j);
    if (i < r) sort(i, r);
}
int main()
{
    int t;
    double x[MAXN], y[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        memset(p, -1, sizeof(p));
        eid = 0;
        scanf("%d%d", &k, &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lf%lf", &x[i], &y[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                double d = dist(x[i], y[i], x[j], y[j]);
                insert(i, j, d);
                insert(j, i, d);
            }
        //print_map();
        prim(1);
        sort(1, n);
        printf("%.2f\n", d[n - k + 1]);
    }
    return 0;
}
