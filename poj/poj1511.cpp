#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
#define MAXN 2000000
#define MAXM 2000000
#define INF 100000000000000LL
using namespace std;
struct edge{
    long long v, d, next;
}e1[MAXM], e2[MAXM];
long long p1[MAXN], p2[MAXN], eid1, eid2, n, m;
void insert1(long long x, long long y, long long d)
{
    e1[eid1].v = y;
    e1[eid1].d = d;
    e1[eid1].next = p1[x];
    p1[x] = eid1++;
}
void insert2(long long x, long long y, long long d)
{
    e2[eid2].v = y;
    e2[eid2].d = d;
    e2[eid2].next = p2[x];
    p2[x] = eid2++;
}
void mapinit()
{
    memset(p1, -1, sizeof(p1));
    memset(p2, -1, sizeof(p1));
    eid1 = eid2 = 0;
}
bool inq[MAXN], vst[MAXN];
long long cnt[MAXN];
long long d1[MAXN], d2[MAXN];
bool spfa1(long long v)
{
    memset(cnt, 0, sizeof(cnt));
    memset(inq, false, sizeof(inq));
    for (long long i = 1; i <= n; ++i)
        d1[i] = INF;
    cnt[v] = 1;
    inq[v] = true;
    queue<long long> q;
    q.push(v);
    d1[v] = 0;
    while (!q.empty())
    {
        long long x = q.front();
        vst[x] = true;
        for (long long i = p1[x]; i != -1; i = e1[i].next)
            if (d1[x] + e1[i].d < d1[e1[i].v])
            {
                d1[e1[i].v] = d1[x] + e1[i].d;
                if (!inq[e1[i].v])
                {
                    inq[e1[i].v] = true;
                    q.push(e1[i].v);
                    cnt[e1[i].v]++;
                    if (cnt[e1[i].v] > n) return true;//有负环则返回true
                }
            }
        inq[x] = false;
        q.pop();
    }
    return false;
}
bool spfa2(long long v)
{
    memset(cnt, 0, sizeof(cnt));
    memset(inq, false, sizeof(inq));
    for (long long i = 1; i <= n; ++i)
        d2[i] = INF;
    cnt[v] = 1;
    inq[v] = true;
    queue<long long> q;
    q.push(v);
    d2[v] = 0;
    while (!q.empty())
    {
        long long x = q.front();
        vst[x] = true;
        for (long long i = p2[x]; i != -1; i = e2[i].next)
            if (d2[x] + e2[i].d < d2[e2[i].v])
            {
                d2[e2[i].v] = d2[x] + e2[i].d;
                if (!inq[e2[i].v])
                {
                    inq[e2[i].v] = true;
                    q.push(e2[i].v);
                    cnt[e2[i].v]++;
                    if (cnt[e2[i].v] > n) return true;//有负环则返回true
                }
            }
        inq[x] = false;
        q.pop();
    }
    return false;
}
int x;
bool init()
{
    mapinit();
    if (scanf("%lld%lld%lld", &n, &m, &x) == EOF) return false;
    long long x, y, d;
    for (long long i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &x, &y, &d);
        insert1(x, y, d);
        insert2(y, x, d);
    }
    return true;
}
int main()
{
    while (init())
    {
        spfa1(x);
        spfa2(x);
        long long res = 0;
        for (long long i = 2; i <= n; ++i)
            res = max(res, d1[i] + d2[i]);
        printf("%lld\n", res);
    }
    return 0;
}
