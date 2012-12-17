#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 512
using namespace std;
int t, n, map[MAXN][MAXN];
bool vst[MAXN];
int d[MAXN];
int prim()
{
    memset(vst, false, sizeof(vst));
    for (int i = 1; i <= n; ++i) d[i] = INT_MAX / 2;
    d[1] = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a, b = INT_MAX;
        for (int j = 1; j <= n; ++j)
            if ((!vst[j]) && (d[j] < b))
            {
                b = d[j], a = j;
            }
        vst[a] = true;
        d[a] = 0;
        res = max(res, b);
        for (int j = 1; j <= n; ++j)
            if ((map[a][j] < d[j]) && !vst[j])
                d[j] = map[a][j];
    }
    return res;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(map, 0, sizeof(map));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &map[i][j]);
        printf("%d\n", prim());
    }
    return 0;
}
