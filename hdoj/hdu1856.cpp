#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000010
using namespace std;
int m, x, y, fa[N], n = 1000000, cnt[N];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
int main()
{
    while (~scanf("%d", &m))
    {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            int fx = father(x), fy = father(y);
            if (fx != fy) fa[fx] = fy;
        }
        memset(cnt, 0, sizeof(cnt));
        int res = 0;
        for (int i = 1; i <= n; ++i) fa[i] = father(fa[i]);
        for (int i = 1; i <= n; ++i) cnt[fa[i]]++;
        for (int i = 1; i <= n; ++i) res = max(res, cnt[i]);
        printf("%d\n", res);

    }
    return 0;
}
