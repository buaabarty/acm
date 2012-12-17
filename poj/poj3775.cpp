#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#define N 110
#define M 60
using namespace std;
int map[N][N], n, m, x, y, z;
vector<int> ch[N];
int fa[N], d[N];
bool use[N];
double dp[N][M], dat[N][M], f[N];
void build_tree()
{
    for (int i = 1; i <= n; ++i) ch[i].clear();
    memset(use, false, sizeof(use));
    for (int i = 1; i <= n; ++i) d[i] = INT_MAX / 3;
    d[1] = 0;
    memset(fa, -1, sizeof(fa));
    for (int i = 1; i <= n; ++i)
    {
        int a = -1, b = INT_MAX / 2;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (d[j] < b))
            {
                a = j, b = d[j];
            }
        if (a == -1) break;
        use[a] = true;
        for (int j = 1; j <= n; ++j)
            if ((b + map[a][j] < d[j]) && !use[j])
            {
                d[j] = b + map[a][j];
                fa[j] = a;
            }
    }
    for (int i = 1; i <= n; ++i)
        if (fa[i] > 0) ch[fa[i]].push_back(i);
}
void dfs(int v, double p)
{
    f[v] = p;
    for (int i = 0, l = ch[v].size(); i < l; ++i)
        dfs(ch[v][i], p / (double)l);
}
double temp[M];
void tree_dp(int v)
{
//    printf("%d\n", v);
    int f = 0;
    int l = ch[v].size();
    for (int i = 0; i <= m; ++i) dp[v][i] = dat[v][i];
    if (l == 0) return;
    for (int i = 0; i < l; ++i) tree_dp(ch[v][i]);
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < l; ++i)
    {
        for (int j = m; j >= 1; --j)
            for (int k = 0; k <= j; ++k)
                temp[j] = max(temp[j], temp[j - k] + dp[ch[v][i]][k] / l);
    }
    for (int i = m; i >= 1; --i)
        for (int j = 0; j <= i; ++j)
            dp[v][i] = max(dp[v][i], dp[v][j] + (1 - dp[v][j]) * temp[i - j]);
    for (int i = 0; i <= m; ++i)
        dp[v][i] = max(dp[v][i], temp[i]);
}
int main()
{
    int a;
    while (scanf("%d%d", &n, &a), (n + a))
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) map[i][j] = INT_MAX / 3;
        for (int i = 1; i <= n; ++i) map[i][i] = 0;
        for (int i = 1; i <= a; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            map[x + 1][y + 1] = min(map[x + 1][y + 1], z);
            map[y + 1][x + 1] = min(map[y + 1][x + 1], z);
        }
        scanf("%d", &m);
        build_tree();
        dfs(1, 1.0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%lf", &dat[i][j]);
            }
        memset(dp, 0, sizeof(dp));
        tree_dp(1);
        printf("%.2f\n", dp[1][m] * 100);
    }
    return 0;
}
