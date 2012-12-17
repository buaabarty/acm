#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define LL long long
#define INF (1LL << 31LL) - 1LL
#define N 256
#define M 65536
using namespace std;
struct edge
{
    LL v, next;
}e[M];
LL eid, p[N], n;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(LL x, LL y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool use[N];
LL match[N];
bool hungary(LL v)
{
    for (LL i = p[v]; i != -1; i = e[i].next)
    {
        LL u = e[i].v;
        if (!use[u])
        {
            use[u] = true;
            LL temp = match[u];
            match[u] = v;
            if (temp == 0 || hungary(temp)) return true;
            match[u] = temp;
        }
    }
    return false;
}
LL calc()
{
    memset(match, 0, sizeof(match));
    LL cnt = 0;
    for (LL i = 1; i <= n; i++)
    {
        memset(use, false, sizeof(use));
        if (hungary(i)) cnt++;
    }
    return cnt;
}
void print_map()
{
    for (LL i = 1; i <= n; ++i)
    {
        printf("%I64d: ", i);
        for (LL j = p[i]; j != -1; j = e[j].next)
            printf("%I64d ", e[j].v);
        puts("");
    }
}
LL h, a, nh[N], mh[N], na[N], ma[N], dat[N][N];
bool okay(LL limit)
{
    mapinit();
    for (LL i = 1; i <= h; ++i)
        for (LL j = 1; j <= a; ++j)
            if ((limit >= dat[i][j]) && ((nh[i] >= dat[i][j] * ma[j] + na[j]) || (nh[i] + mh[i] * (limit - dat[i][j]) >= na[j] + ma[j] * limit))) insert(i, j);
    n = h;
    //print_map();
    //printf("%I64d\n", calc());
    return calc() == a;
    //return true;
}
int main()
{
    while (scanf("%I64d%I64d", &h, &a), (h + a))
    {
        for (LL i = 1; i <= h; ++i) scanf("%I64d%I64d", &nh[i], &mh[i]);
        for (LL i = 1; i <= a; ++i) scanf("%I64d%I64d", &na[i], &ma[i]);
        for (LL i = 1; i <= h; ++i)
            for (LL j = 1; j <= a; ++j)
                scanf("%I64d", &dat[i][j]);
        LL left = 0, right = INF, mid;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (!okay(left)) left = right;
                break;
            }
            mid = (left + right) / 2;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        if (!okay(left)) puts("IMPOSSIBLE");
        else printf("%I64d\n", left);
    }
    return 0;
}
