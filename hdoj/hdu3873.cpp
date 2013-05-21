#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#define LL long long
#define N 3010
#define M 10000000
using namespace std;
struct edge
{
    LL v, d, next;
}e[M], e2[M];
LL p[N], eid, p2[N], eid2;
void mapinit()
{
    eid = 0;
    memset(p, -1, sizeof(p));
}
void map2init()
{
    eid2 = 0;
    memset(p2, -1, sizeof(p2));
}
void insert(LL x, LL y, LL d)
{
    e[eid].v = y;
    e[eid].next = p[x];
    e[eid].d = d;
    p[x] = eid++;
}
void insert2(LL x, LL y)
{
    e2[eid2].v = y;
    e2[eid2].next = p2[x];
    p2[x] = eid2++;
}
LL n, dist[N], les[N], m, x, y, z, k, rd[N];
bool map[N][N], vst[N];
LL INF;
struct node{
    int v, d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node(int a, int b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
void dijkstra(LL v)
{
    /*for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    for (LL i = 1; i <= n; ++i) printf("%I64d ", rd[i]);
    puts("");*/
    for (LL i = 1; i <= n; ++i) dist[i] = INT_MAX;
    for (LL i = 1; i <= n; ++i) dist[i] = dist[i] * 1000000LL;
    memset(les, 0, sizeof(les));
    INF = dist[v];
    dist[v] = 0;
    while (!q.empty()) q.pop();
    q.push(node(v, 0));
    memset(vst, false, sizeof(vst));
    while (!q.empty())
    {
        int x = q.top().v; q.pop();
        if (vst[x]) continue;
        vst[x] = true;
      //  printf("AAAA%d\n", x);
        for (int i = p2[x]; i != -1; i = e2[i].next)
        {
        //    printf("AAA%d\n", e2[i].v);
            rd[e2[i].v]--;
            les[e2[i].v] = max(les[e2[i].v], dist[x]);
            if ((dist[e2[i].v] < INF) && (rd[e2[i].v] == 0))
            {
                dist[e2[i].v] = max(dist[e2[i].v], les[e2[i].v]);
                q.push(node(e2[i].v, dist[e2[i].v]));
            }
        }
        for (int i = p[x]; i != -1; i = e[i].next)
            if (e[i].d + dist[x] < dist[e[i].v])
            {
                dist[e[i].v] = max(les[e[i].v], e[i].d + dist[x]);
                if (rd[e[i].v] == 0) q.push(node(e[i].v, dist[e[i].v]));
            }
    }
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p2[i]; j != -1; j = e2[j].next)
            printf("%I64d ", e2[j].v);
        printf("\n");
    }
}
void PrintMap()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%I64d ", e[j].v);
        printf("\n");
    }
}
int main()
{
    //freopen("invade.in", "r", stdin);
    //freopen("ans.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d%I64d", &n, &m);
        mapinit();
        map2init();
        for (LL i = 1; i <= m; ++i)
        {
            scanf("%I64d%I64d%I64d", &x, &y, &z);
            insert(x, y, z);
        }
        memset(rd, 0, sizeof(rd));
        for (LL i = 1; i <= n; ++i)
        {
            scanf("%I64d", &k);
            while (k--)
            {
                scanf("%I64d", &x);
                insert2(x, i);
                rd[i]++;
            }
        }
        dijkstra(1);
//        for (LL i = 1; i <= n; ++i)
//            printf("%I64d ", da[i]);
//        puts("");
//        for (LL i = 1; i <= n; ++i)
//            printf("%I64d ", db[i]);
//        puts("");
    //    print_map();
    //    PrintMap();
        printf("%I64d\n", dist[n]);
    }
    return 0;
}
