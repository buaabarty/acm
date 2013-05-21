#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#define M 10000000
#define N 512
#define eps 1e-5
using namespace std;
struct edge{
    int v, next;
}e[M];
int eid, p[N];
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
double x[N], y[N];
int n, m;
int dfn[N], low[N], stack[N], belong[N];
int bcnt, dindex = 0, top = 0;
bool instack[N];
void tarjan(int v)
{
    instack[v] = true;
    stack[++top] = v;
    dfn[v] = low[v] = ++dindex;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        if (!dfn[e[i].v])
        {
            tarjan(e[i].v);
            low[v] = min(low[v], low[e[i].v]);
        }
        else if (instack[e[i].v])
        {
            low[v] = min(low[v], dfn[e[i].v]);
        }
    }
    int temp;
    if (dfn[v] == low[v])
    {
        bcnt++;
        do{
            temp = stack[top--];
            instack[temp] = false;
            belong[temp] = bcnt;
        }while (temp != v);
    }
}
void solve()
{
    memset(dfn, 0, sizeof(dfn));
    top = bcnt = dindex = 0;
    for (int i = 1; i <= 2 * n; ++i)
        if (!dfn[i]) tarjan(i);
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("");
    }
}
double sqr(double x)
{
    return x * x;
}
double dist(double ax, double ay, double bx, double by)
{
    return sqrt(sqr(ax - bx) + sqr(ay - by));
}
int opp(int x)
{
    if (x <= n) return x + n;
    else return x - n;
}
bool okay(double limit)
{
    mapinit();
    for (int i = 1; i <= n * 2; ++i)
        for (int j = 1; j <= n * 2; ++j) if ((i != j) && (i != opp(j)))
        {
            if (dist(x[i], y[i], x[j], y[j]) <= limit)
            {
                insert(i, opp(j));
                insert(j, opp(i));
            }
        }
    solve();
    for (int i = 1; i <= n; ++i)
        if (belong[i] == belong[i + n]) return false;
    return true;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%lf%lf%lf%lf", &x[i], &y[i], &x[i + n], &y[i + n]);
        double mid, left = 0, right = 1e7;
        while (right > left + eps)
        {
            mid = (left + right) / 2;
            if (okay(mid)) left = mid;
            else right = mid;
        }
        printf("%.2lf\n", round(left / 2.0 * 100.0) / 100.0);
    }
    return 0;
}
