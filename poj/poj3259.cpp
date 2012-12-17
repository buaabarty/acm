#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXN 1024
#define MAXM 8192
using namespace std;
typedef struct{
    int v, d, next;
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

int n, m, w, a, b, c;
int f[MAXN];

bool init()
{
    einit();
    if (scanf("%d%d%d", &n, &m, &w) == EOF) return false;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, c);
        insert(b, a, c);
    }
    for (int i = 1; i <= w; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, -c);
    }
    return true;
}

bool inq[MAXN], vst[MAXN];
int cnt[MAXN];
int d[MAXN];

bool spfa(int v)
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
        vst[x] = true;
        for (int i = p[x]; i != -1; i = e[i].next)
            if (d[x] + e[i].d < d[e[i].v])
            {
                d[e[i].v] = d[x] + e[i].d;
                if (!inq[e[i].v])
                {
                    inq[e[i].v] = true;
                    q.push(e[i].v);
                    cnt[e[i].v]++;
                    if (cnt[e[i].v] > n) return true;
                }
            }
        inq[x] = false;
        q.pop();
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        bool found = false;
        memset(vst, false, sizeof(vst));
        for (int i = 1; i <= n; ++i)
            if (!vst[i])
            {
                if (spfa(i))
                {
                    found = true;
                    break;
                }
            }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
