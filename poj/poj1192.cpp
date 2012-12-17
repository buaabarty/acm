#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1024
#define MAXM 32768
using namespace std;
struct edge{
    int v, next;
    bool in_tree;
}e[MAXM];
int n, root, p[MAXN] , c[MAXN], eid;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool vst[MAXN];
void make_tree(int v)
{
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]){
            e[i].in_tree = true;
            make_tree(e[i].v);
        }
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int x[MAXN], y[MAXN];
bool connect(int i, int j)
{
    return (iabs(x[i] - x[j]) + iabs(y[i] - y[j])) == 1;
}
void init()
{
    memset(p, -1, sizeof(p));
    memset(e, 0, sizeof(e));
    eid = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
        for (int j = 1; j < i; ++j)
            if (connect(j, i)){
                insert(i, j);
                insert(j, i);
            }
    }
    root = 1;
    memset(vst, false, sizeof(vst));
    make_tree(root);
}
int dp[MAXN][2];
void dfs(int v)
{
    int s = 0, m = INT_MIN;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (e[i].in_tree){
            dfs(e[i].v);
            m = max(m, max(dp[e[i].v][0], dp[e[i].v][1]));
            if (dp[e[i].v][1] > 0) s += dp[e[i].v][1];
        }
    dp[v][0] = m;
    dp[v][1] = s + c[v];
}
int main()
{
    init();
    dfs(root);
    int res = INT_MIN;
    for (int i = 1; i <= n; ++i)
        res = max(res, max(dp[i][0], dp[i][1]));
    printf("%d\n", res);
    return 0;
}
