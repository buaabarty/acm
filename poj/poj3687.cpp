#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 256
#define MAXM 65536
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid, rd[MAXN], use[MAXN];
int n, m;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
queue<int> q;
int res[MAXN], l = 0;
bool topsort()
{
    memset(use, false, sizeof(use));
    l = 0;
    memset(res, 0, sizeof(res));
    int i;
    for (i = n; i >= 1; --i)
    {
        int j = 0;
        for (j = n; j >= 1; --j)
            if (!use[j] && !rd[j]) break;
        if (j == 0) break;
        use[j] = true;
        res[j] = i;
        for (int k = p[j]; k != -1; k = e[k].next) --rd[e[k].v];
    }
    return (!i);
}
int main()
{
    int __;
    scanf("%d", &__);
    while (__--)
    {
        int x, y;
        memset(p, -1, sizeof(p));
        memset(rd, 0, sizeof(rd));
        eid = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            insert(y, x);
            ++rd[x];
        }
        if (topsort())
        {
            for (int i = 1; i < n; ++i) printf("%d ", res[i]);
            printf("%d\n", res[n]);
        }
        else printf("-1\n");
    }
    return 0;
}
