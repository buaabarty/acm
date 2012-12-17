#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXM 131072
#define MAXL 2048
#define MAXN 2048
using namespace std;
typedef struct edge{
    int v, d, next;
}EDGE;
EDGE e[MAXM];
int eid, p[MAXN];
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}

int n, len[MAXN], x, y, map[MAXN][MAXN];
char str[MAXL];

int ord(char x, char y)
{
    return (x - 'a') * 26 + y - 'a' + 1;
}

void print()
{
    for (int i = 1; i <= n; ++i)
        if (p[i] != -1)
        {
            printf("%d:", i);
            for (int j = p[i]; j != -1; j = e[j].next)
                printf("(%d,%d)", e[j].v, e[j].d);
            printf("\n");
        }
}

bool init()
{
    scanf("%d", &n);
    if (n == 0) return false;
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    memset(map, 0, sizeof(map));
    eid = 0;
    int a, b;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        len[i] = strlen(str);
        if (len[i] < 2) continue;
        a = ord(str[0], str[1]);
        b = ord(str[len[i] - 2], str[len[i] - 1]);
        map[a][b] = max(map[a][b], len[i]);
    }
    n = 26 * 26;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (map[i][j]) insert(i, j, map[i][j]);
    //print();
    return true;
}

bool vst[MAXN], inq[MAXN];
double d[MAXN];
int cnt[MAXN];
queue<int> q;

bool spfa(int v, double f)
{
    memset(inq, false, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
        d[i] = 1e10;
    while (!q.empty()) q.pop();
    q.push(v);
    vst[v] = true;
    inq[v] = true;
    cnt[v] = 1;
    while (!q.empty())
    {
        int x = q.front();
        inq[x] = false;
        q.pop();
        for (int i = p[x]; i != -1; i = e[i].next)
            if (d[x] + f - (double)e[i].d < d[e[i].v])
            {
                d[e[i].v] = d[x] - (double)e[i].d + f;
                if (!inq[e[i].v])
                {
                    cnt[e[i].v]++;
                    if (cnt[e[i].v] >= n) return false;
                    if (e[i].v == v) return false;
                    inq[e[i].v] = true;
                    q.push(e[i].v);
                    if (!vst[e[i].v]) vst[e[i].v] = true;
                }
            }
    }
    return true;
}

bool exist(double f)
{
    memset(vst, false, sizeof(vst));
    for (int i = 1; i <= n; ++i)
        if (!vst[i])
        {
            if (!spfa(i, f)) return true;
        }
    return false;
}

int main()
{
//    freopen("i1.in", "r", stdin);
    while (init())
    {
        double l = 0, r = 1e5, mid;
        while (fabs(l - r) > 1e-3)
        {
            mid = (l + r) / 2.0;
            if (!exist(mid)) r = mid;
            else l = mid;
        }
        if (fabs(l) > 1e-5) printf("%.2f\n", l);
        else printf("No solution.\n");
    }
    return 0;
}
