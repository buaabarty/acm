#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXN 1024
#define MAXM 8192
using namespace std;
typedef struct{
    int v, next;
    double d;
}edge;

edge e[MAXM];
int p[MAXN], eid;
void einit()
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

int n, m, a, b, c;
int f[MAXN];

bool init()
{
    einit();
    if (scanf("%d%d", &n, &m) == EOF) return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &f[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, c);
    }
    return true;
}

bool inq[MAXN];
int cnt[MAXN];
double d[MAXN];

bool spfa(int v, double r)
{
    memset(cnt, 0, sizeof(cnt));
    memset(inq, false, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        d[i] = 1e20;
    cnt[v] = 1;
    inq[v] = true;
    queue<int> q;
    q.push(v);
    d[v] = 0;
    while (!q.empty())
    {
        int x = q.front();
        for (int i = p[x]; i != -1; i = e[i].next)
            if (d[x] + e[i].d * r - (double)f[x] < d[e[i].v])
            {
                d[e[i].v] = d[x] + e[i].d * r - (double)f[x];
                if (!inq[e[i].v])
                {
                    inq[e[i].v] = true;
                    q.push(e[i].v);
                    cnt[e[i].v]++;
                    if (cnt[e[i].v] > n) return false;
                }
            }
        inq[x] = false;
        q.pop();
    }
    return true;
}

bool okay(double s)
{
    for (int i = 1; i <= 1; ++i)
        if (!spfa(i, s)) return false;
    return true;
}

int main()
{
    while (init())
    {
        double l = 0, r = 1000.0f, mid;
        while (fabs(r - l) > 1e-3)
        {
            mid = (l + r) / 2.0f;
            if (okay(mid)) r = mid;
            else l = mid;
        }
        printf("%.2f\n", l);
    }
    return 0;
}
