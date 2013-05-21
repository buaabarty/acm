#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 510
#define MAXM 50000
#define eps 1e-10
using namespace std;
namespace MCF {
    struct edge{
        int x, y, f, next;
        double c;
    }e[MAXM];
    int eid, p[MAXN];
    int n, m, source, sink;
    int pre[MAXN], path[MAXN];
    double d[MAXN];

    void insert(int x, int y, int f, double c)
    {
        e[eid].x = x;
        e[eid].y = y;
        e[eid].f = f;
        e[eid].c = c;
        e[eid].next = p[x];
        p[x] = eid++;
    }
    void insert1(int x, int y, int f, double c)
    {
        insert(x, y, f, c);
        insert(y, x, 0, -c);
    }
    void insert2(int x, int y, int f, double c)
    {
        insert1(x, y, f, c);
        insert1(y, x, f, c);
    }
    void mapinit()
    {
        memset(p, -1, sizeof(p));
        eid = 0;
    }
    bool spfa(int s)
    {
        queue<int> q;
        bool use[MAXN];
        memset(use, false, sizeof(use));
        int u, v;
        for (int i = 1; i <= n; ++i) d[i] = 1e20;
        while (!q.empty()) q.pop();
        q.push(s);
        d[s] = 0;
        pre[s] = -1;
        use[s] = true;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (int i = p[u]; i != -1; i = e[i].next)
            {
                v = e[i].y;
                if ((e[i].f != 0) && (d[u] + e[i].c < d[v]-eps)){
                    d[v] = d[u] + e[i].c;
                    pre[v] = u;
                    path[v] = i;
                    if (!use[v]){
                        use[v] = true;
                        q.push(v);
                    }
                }
            }
            use[u] = false;
        }
        return (d[sink] < 1e12);
    }
    double argument()
    {
        int delta = 100000000;
        double res = 0;
        for (int i = sink; pre[i] != -1; i = pre[i])
            delta = min(delta, e[path[i]].f);
        for (int i = sink; pre[i] != -1; i = pre[i])
        {
            e[path[i]].f -= delta;
            e[path[i] ^ 1].f += delta;
            res += e[path[i]].c * 1.0 * delta;
        }
        return res;
    }
    double maxcostflow()
    {
        double sum = 0;
        while (spfa(source)) sum += argument();
        return sum;
    }
}



int T, n, n1, n2;
int q1[510], c1[510], q2[510], c2[510];

bool okay(double lim) {
    MCF::mapinit();
    int st = n+3, ed = n+4;
    for (int i = 1; i <= n; ++i)
        MCF::insert1(st, i, 1, 0);
    MCF::insert1(n+1, ed, n1, 0);
    MCF::insert1(n+2, ed, n2, 0);
    for (int i = 1; i <= n; ++i) {
        MCF::insert1(i, n+1, 1, -q1[i]*1.0+lim*c1[i]);
        MCF::insert1(i, n+2, 1, -q2[i]*1.0+lim*c2[i]);
    }
    MCF::n = ed;
    MCF::source = st;
    MCF::sink = ed;
    return (MCF::maxcostflow() < eps);
}

int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &n, &n1, &n2);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", &q1[i], &c1[i], &q2[i], &c2[i]);
        double l = 0, r = 1e8, mid;
        while (r - l > eps) {
            mid = (l + r) / 2.0;
            if (okay(mid)) l = mid;
            else r = mid;
        }
        printf("Case #%d: %.8f\n", ca, l);
        //okay(2.44444444444444);
    }
    return 0;
}
