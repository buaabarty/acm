#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 128
#define MAXM 256
using namespace std;
struct edge{
    int v, d, next;
}e[MAXM];
int p[MAXN], eid;
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
struct node
{
    int v;
    double d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node (int a, double b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
double d[MAXN];
bool use[MAXN];
int n;
int prim(int v)
{
    int s = 0;
    memset(d, 0x7f, sizeof(d));
    memset(use, false, sizeof(use));
    while (!q.empty()) q.pop();
    d[v] = 0;
    q.push(node(v, 0));
    for (int i = 1; i <= n; ++i)
    {
        int mv = q.top().v, ms = q.top().d;
        while (use[mv])
        {
            q.pop();
            mv = q.top().v, ms = q.top().d;
        }
        s += ms;
        q.pop();
        use[mv] = true;
        for (int j = p[mv]; j != -1; j = e[j].next)
            if (d[e[j].v] > e[j].d && !use[e[j].v])
            {
                q.push(node(e[j].v, e[j].d));
                d[e[j].v] = e[j].d;
            }
    }
    return s;
}

bool init()
{
    memset(p, -1, sizeof(p));
    eid = 0;
    int x, y, t, d;
    char c;
    scanf("%d", &n);
    if (!n) return false;
    for (int i = 1; i < n; ++i)
    {
        scanf("\n%c", &c);
        x = c - 'A' + 1;
        scanf("%d", &t);
        while (t--)
        {
            scanf(" %c%d", &c, &d);
            y = c - 'A' + 1;
            insert(x, y, d);
            insert(y, x, d);
        }
    }
    /*for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d)", e[j].v, e[j].d);
        printf("\n");
    }*/
    return true;
}

int main()
{
    //freopen("data.in", "r", stdin);
    while (init())
    {
        printf("%d\n", prim(1));
    }
    fclose(stdin);
    return 0;
}
