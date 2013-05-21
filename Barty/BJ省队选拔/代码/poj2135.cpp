#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 1000000000
#define MAXN 1024
#define MAXM 10485760
using namespace std;
struct edge{
    int x, y, f, c, next;
}e[MAXM];
int eid, p[MAXN];//邻接表数据结构
int n, m, source, sink;//source标记源点，sink标记汇点
int d[MAXN], pre[MAXN], path[MAXN];//pre标记最短路径上节点的前驱，path记录是有哪条边扩展过来的
queue<int> q;//SPFA使用的队列
bool use[MAXN];//标记是否在队列内
void insert(int x, int y, int f, int c)
{
    e[eid].x = x;
    e[eid].y = y;
    e[eid].f = f;
    e[eid].c = c;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert1(int x, int y, int f, int c)
{
    insert(x, y, f, c);
    insert(y, x, 0, -c);
}
void insert2(int x, int y, int f, int c)
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
    for (int i = 1; i <= n; ++i) d[i] = INF;
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
    return (d[sink] != INF);
}
int argument()
{
    int delta = INF, res = 0;
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
int maxcostflow()
{
    int sum = 0;
    while (spfa(source)) sum += argument();
    return sum;
}
bool init()
{
    mapinit();
    if (scanf("%d%d", &n, &m) == EOF) return false;
    int x, y, d;
    source = n + 1, sink = n + 2;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &d);
        insert2(x, y, 1, d);
    }
    insert1(source, 1, 2, 0);
    insert1(n, sink, 2, 0);
    n = sink;
    return true;
}
int main()
{
    while (init())
        printf("%d\n", maxcostflow());
    return 0;
}
