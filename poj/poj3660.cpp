#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 128
using namespace std;
bool map[MAXN][MAXN];
int rd[MAXN];
int n, x, m, y;
bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    memset(map, false, sizeof(map));
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
    return true;
}
int res()
{
    int s = 0, s1;
    for (int i = 1; i <= n; ++i)
    {
        s1 = 0;
        for (int j = 1; j <= n; ++j)
            s1 += (map[i][j] + map[j][i]);
        s += (s1 == n - 1);
    }
    return s;
}
int main()
{
    while (init())
    {
        printf("%d\n", res());
    }
    return 0;
}
