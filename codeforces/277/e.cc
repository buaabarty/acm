#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
namespace G {
    const int MAXN = 1001;
    const int MAXM = 1000001;
    struct edge{
        int x, y, f, next;
        double c;
    }e[MAXM];
    int eid, p[MAXN];//邻接表数据结构
    int n, m, source, sink;//source标记源点，sink标记汇点
    double d[MAXN];
    int pre[MAXN], path[MAXN];//pre标记最短路径上节点的前驱，path记录是有哪条边扩展过来的
    queue<int> q;//SPFA使用的队列
    bool use[MAXN];//标记是否在队列内
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
                if ((e[i].f != 0) && (d[u] + e[i].c < d[v])){
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
        return (d[sink] < 1e20);
    }
    double argument()
    {
        int delta = 1000000000;
        double res = 0;
        for (int i = sink; pre[i] != -1; i = pre[i])
            delta = min(delta, e[path[i]].f);
        for (int i = sink; pre[i] != -1; i = pre[i])
        {
            e[path[i]].f -= delta;
            e[path[i] ^ 1].f += delta;
            res += e[path[i]].c * delta;
        }
        return res;
    }
    double maxcostflow()
    {
        double sum = 0;
        while (spfa(source)) {
            sum += argument();
        }
        return sum;
    }
}

struct point {
    int x, y;
} p[1000];
int n;

double sqr(int x) {
    return x * x;
}

double dist(int x, int y) {
    return sqrt(fabs(sqr(p[x].x-p[y].x)+sqr(p[x].y-p[y].y)));
}

int main() {
    G::mapinit();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    G::source = n * 2 + 1;
    G::sink = n*2+2;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (p[i].y > p[j].y) G::insert1(i, j+n, 1, dist(i, j));
    for (int i = 1; i <= n; ++i) {
        G::insert1(G::source, i, 2, 0);
        G::insert1(i+n, G::sink, 1, 0);
    }
    G::n = G::sink;
    double ans = G::maxcostflow();
    int tot = 0;
    for (int i = G::p[G::sink]; i != -1; i = G::e[i].next)
        if (G::e[i].f) ++tot;
    if (tot != n - 1) puts("-1");
    else printf("%.10lf\n", ans);
    return 0;
}
