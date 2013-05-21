#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 128
#define M 65536
using namespace std;
int d[N], pow[N], sum, f[M], n, m;
bool use[N];
struct edge
{
    int v, d, next;
}e[M];
int p[N], eid;
void mapinit()
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
void insert2(int x, int y, int d)
{
    insert(x, y, d);
    insert(y, x, d);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            insert2(a, b, c);
        }
        for (int i = 1; i <= n; ++i) d[i] = INT_MAX / 3;
        d[0] = 0;
        memset(use, false, sizeof(use));
        for (int i = 1; i <= n; ++i)
        {
            int mt, md = INT_MAX;
            for (int j = 0; j <= n; ++j)
                if (!use[j] && (d[j] < md))
                {
                    md = d[j];
                    mt = j;
                }
            use[mt] = true;
            for (int j = p[mt]; j != -1; j = e[j].next)
                if (!use[e[j].v]) d[e[j].v] = min(d[e[j].v], md + e[j].d);
        }

        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &pow[i]);
            sum += pow[i];
        }
        for (int i = 1; i <= sum; ++i) f[i] = INT_MAX / 3;
        f[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = sum; j >= pow[i]; --j)
                f[j] = min(f[j], f[j - pow[i]] + d[i]);
        }
        int res = INT_MAX;
        for (int i = sum / 2 + 1; i <= sum; ++i)
            res = min(res, f[i]);
        if (res < INT_MAX / 3) printf("%d\n", res);
        else printf("impossible\n");
    }
    return 0;
}
