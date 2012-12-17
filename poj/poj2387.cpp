#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 1024
#define MAXM 8192
#define MAX_INT 1000000000
using namespace std;
typedef struct{
    int v, d, next;
}edge;
int t, n, a, b, c;
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

bool inq[MAXN], vst[MAXN];
int cnt[MAXN];
int d[MAXN];
bool spfa(int v)
{
    memset(cnt, 0, sizeof(cnt));
    memset(inq, false, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        d[i] = MAX_INT;
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
                    if (cnt[e[i].v] > n) return true;//有负环则返回true
                }
            }
        inq[x] = false;
        q.pop();
    }
    return false;
}



int main()
{
    einit();
    scanf("%d%d", &t, &n);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        insert(a, b, c);
        insert(b, a, c);
    }
    spfa(n);
    cout << d[1] << endl;
    return 0;
}
