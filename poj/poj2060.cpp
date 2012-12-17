#include <iostream>
#include <cstdio>
#include <cstring>
#define N 512
#define M 1048576
using namespace std;
int n, t[N], sx[N], sy[N], tx[N], ty[N];
struct edge
{
    int v, next;
}e[M];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool use[N];
int match[N];
bool hungary(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (!use[u])
        {
            use[u] = true;
            int temp = match[u];
            match[u] = v;
            if (temp == 0 || hungary(temp)) return true;
            match[u] = temp;
        }
    }
    return false;
}
int calc()
{
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(use, false, sizeof(use));
        if (hungary(i)) cnt++;
    }
    return cnt;
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(int ax, int ay, int bx, int by)
{
    return iabs(ax - bx) + iabs(ay - by);
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: ", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        puts("");
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            int a, b;
            scanf("%d:%d%d%d%d%d", &a, &b, &sx[i], &sy[i], &tx[i], &ty[i]);
            t[i] = a * 60 + b;
        }
        mapinit();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) if (i != j)
            {
//                printf("%d %d %d %d\n", t[i], dist(sx[i], sy[i], tx[i], ty[i]), dist(tx[i], ty[i], sx[j], sy[j]),  t[j]);
                if (t[i] + dist(sx[i], sy[i], tx[i], ty[i]) + dist(tx[i], ty[i], sx[j], sy[j]) < t[j])
                    insert(i, j);
            }
//        print_map();
        printf("%d\n", n - calc());
    }
    return 0;
}
