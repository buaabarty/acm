#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int v, next;
}e[3100];
int p[1510], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(const int x, const int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(const int x, const int y)
{
    insert(x, y);
    insert(y, x);
}
int son[1510], n;
bool vst[1510];
vector<int> ch[1510];
void build(const int v)
{
    ch[v].clear();
    vst[v] = 1;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            build(e[i].v);
            son[v] += son[e[i].v];
            ch[v].push_back(e[i].v);
        }
    son[v]++;
}
class node
{
public:
    int x, y, res, ori;
    bool operator < (const node a) const
    {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
}d[1510], o;
bool cmp2(const node a, const node b)
{
    return (long long)(a.x - o.x) * (long long)(b.y - o.y) < (long long)(a.y - o.y) * (long long)(b.x - o.x);
}
void dfs(const int v, const int l, const int r)
{
    int j = l;
    o = d[l];
    for (int i = l + 1; i <= r; ++i)
        if (d[i] < o)
        {
            o = d[i];
            j = i;
        }
    swap(d[l], d[j]);
    d[l].res = v;
    //printf("%d %d %d %d\n", v, l, d[l].x, d[l].y);
    sort(d + l + 1, d + r + 1, cmp2);
    int chs = ch[v].size(), now = l + 1;
    for (int i = 0; i < chs; ++i)
    {
        dfs(ch[v][i], now, now + son[ch[v][i]] - 1);
        now += son[ch[v][i]];
    }
}
int res[1510];
int main()
{
    //freopen("input.txt", "r", stdin);
    mapinit();
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert2(x, y);
    }
    memset(vst, 0, sizeof(vst));
    build(1);
    //for (int i = 1; i <= n; ++i)
    //    printf("%d,%d\t", son[i], ch[i].size());
    //puts("");
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &d[i].x, &d[i].y);
        //printf("%d %d\n", d[i].x, d[i].y);
        d[i].ori = i;
    }
    //for (int i = 1; i <= n; ++i)
    //    printf("%d %d %d\n", d[i].ori, d[i].x, d[i].y);
    dfs(1, 1, n);
    for (int i = 1; i <= n; ++i)
        res[d[i].ori] = d[i].res;
    for (int i = 1; i < n; ++i)
        printf("%d ", res[i]);
    printf("%d\n", res[n]);
    //for (int i = 1; i <= n; ++i)
    //    printf("%d %d\n", d[i].x, d[i].y);
    return 0;
}
