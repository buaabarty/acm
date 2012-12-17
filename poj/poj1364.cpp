#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <climits>
#define MAXN 128
#define MAXM 1024
using namespace std;
typedef struct edge{
    int v, d, next;
}EDGE;
EDGE e[MAXM];
int p[MAXN], eid;
void insert(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, m, x, y, z, st, ed;
string str;
bool init()
{
    scanf("%d", &n);
    if (n == 0) return false;
    scanf("%d", &m);
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    eid = 0;
    st = n + 1;
    ed = n + 2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> str >> z;
        if (str == "gt") insert(x + y, x - 1, -z - 1);
        else insert(x - 1, x + y, z - 1);
    }
    for (int i = 0; i <= n; ++i)
    {
        insert(st, i, 0);
        insert(i, ed, 0);
    }
    n += 2;
    return true;
}
void print()
{
    for (int i = 0; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[j].d);
        printf("\n");
    }
}
int dist[MAXN];
bool instack[MAXN];
bool vst[MAXN];
bool DFS_SPFA(int v)
{
    vst[v] = true;
    instack[v] = true;
    bool res = false;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (dist[v] + e[i].d < dist[e[i].v])
        {
            dist[e[i].v] = dist[v] + e[i].d;
            if (!instack[e[i].v])
            {
                if (DFS_SPFA(e[i].v)) res = true;
            }
            else res = true;
            if (res) break;
        }
    instack[v] = false;
    return res;
}
bool HasCircle()
{
    for (int i = 0; i <= n; ++i) dist[i] = INT_MAX / 3;
    memset(instack, false, sizeof(instack));
    memset(vst, false, sizeof(vst));
    dist[st] = 0;
    return DFS_SPFA(st);
}
int main()
{
    while (init())
    {
        //print();
        if (HasCircle()) cout << "successful conspiracy";
        else cout << "lamentable kingdom";
        cout << endl;
    }
    return 0;
}
