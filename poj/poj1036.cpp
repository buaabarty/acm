#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 128
#define MAXT 32768
using namespace std;
struct gangsters{
    int  t, p, s;
}g[MAXN];
bool cmp(gangsters a, gangsters b)
{
    return a.t < b.t;
}
int n, k, t;
int dp[2][MAXN];
void init()
{
    scanf("%d%d%d", &n, &k, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i].t);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i].p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i].s);
    sort(g + 1, g + n + 1, cmp);
}
int main()
{
    init();
    memset(dp, 0, sizeof(dp));
    int f = 0;
    for (int i = t; i >= 0; --i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int l = j - 1; l <= j + 1; ++l)
                if ((l >= 0) && (l <= k)) dp[f][j] = max(dp[1-f][l], dp[f][j]);
            int sum = 0;
            for (int m = 1; m <= n; ++m)
                if ((g[m].t == i) && (g[m].s == j)) sum += g[m].p;
                else if (g[m].t > i) break;
            dp[f][j] += sum;
        }
#ifdef DEBUG
        for (int j = 0; j <= k; ++j)
            printf("%3d", dp[f][j]);
        printf("\n");
#endif
        f = 1 - f;
        memset(dp[f], 0, sizeof(dp[f]));
    }
    printf("%d\n", dp[1 - f][0]);
    return 0;
}
