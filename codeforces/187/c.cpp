#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1000000000
using namespace std;
struct edge
{
    int v, next;
}e[400010];
int p[100010], eid, s, t;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
bool got[100010];
int minn[100010];
bool dfs(int v, int last, int limit)
{
    if (v == t) return true;
    if (got[v])
    {
        last = 0;
    }
    minn[v] = last;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (minn[e[i].v] > last + 1)
        {
            if (last + 1 <= limit)
            {
                if (dfs(e[i].v, last + 1, limit)) return true;
            }
        }
    return false;
}
int n, m, k;
bool okay(int limit)
{
    for (int i = 1; i <= n; ++i) minn[i] = INF;
    return dfs(s, 0, limit);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    memset(got, 0, sizeof(got));
    for (int i = 1; i <= k; ++i)
    {
        int x;
        scanf("%d", &x);
        got[x] = 1;
    }
    mapinit();
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert2(x, y);
    }
    scanf("%d%d", &s, &t);
    got[s] = 1;
    got[t] = 1;
    int left = 1, right = n;
    while (left < right)
    {
        if (left + 1 == right)
        {
            if (!okay(left)) left = right;
            break;
        }
        int mid = (left + right) >> 1;
        if (okay(mid)) right = mid;
        else left = mid + 1;
    }
    if (left == n) printf("-1\n");
    else printf("%d\n", left);
    return 0;
}
