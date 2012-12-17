#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 210
using namespace std;
int f[MAXN][MAXN][MAXN], dat[MAXN], n;
int dfs(int l, int r, int k)
{
    if (f[l][r][k] != -1) return f[l][r][k];
    if (l > r) return 0;
    if (l == r)
    {
        f[l][r][k] = (k + 1) * (k + 1);
        return f[l][r][k];
    }
    f[l][r][k] = dfs(l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; ++i)
        if (dat[i] == dat[r])
        {
            f[l][r][k] = max(f[l][r][k], dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
        }
    return f[l][r][k];
}
int main()
{
    int __;
    scanf("%d", &__);
    for (int ca = 1; ca <= __; ++ca)
    {
        scanf("%d", &n);
        memset(f, -1, sizeof(f));
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            scanf("%d", &dat[i]);
        printf("Case %d: %d\n", ca, dfs(1, n, 0));
    }
    return 0;
}
