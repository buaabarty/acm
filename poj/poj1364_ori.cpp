#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
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
    for (int i = 1; i <= n; ++i)
    {
        insert(st, i, 0);
        insert(i, ed, 0);
    }
    n += 2;
    return true;
}
void print()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[j].d);
        printf("\n");
    }
}
queue<int> q;
bool inq[MAXN];
int d[MAXN], cnt[MAXN];
bool spfa(int v)
{
    memset(inq, false, sizeof(inq));
    memset(d, 0x7f, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    inq[v] = 0;
    q.push(v);
    d[v] = 0;
    cnt[v] = 1;
    while (!q.empty())
    {
        x = q.front();
        inq[x] = false;
        for (int i = p[x]; i != -1; i = e[i].next)
        {
            y = e[i].v;
            if (d[x] + e[i].d < d[y])
            {
                d[y] = d[x] + e[i].d;
                if (!inq[y])
                {
                    q.push(y);
                    inq[y] = true;
                    cnt[y]++;
                    if (cnt[y] > n) return false;
                }
            }
        }
        q.pop();
    }
//    for (int i = 1; i <= n; ++i)
//        printf("%d ", d[i]);
//    printf("\n");
    return true;
}
int main()
{
    while (init())
    {
        print();
        if (!spfa(st)) cout << "successful conspiracy";
        else cout << "lamentable kingdom";
        cout << endl;
    }
    return 0;
}
