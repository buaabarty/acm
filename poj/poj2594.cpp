#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 510
using namespace std;
bool map[MAX_N][MAX_N];
bool vst[MAX_N];
int link[MAX_N], n;
bool dfs(int v)
{
    for (int i = 1; i <= n; ++i)
        if (!vst[i] && map[v][i])
        {
            vst[i] = true;
            if (link[i] == -1 || dfs(link[i]))
            {
                link[i] = v;
                return true;
            }
        }
    return false;
}
void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = map[i][j] || map[i][k] && map[k][j];
}
bool init()
{
    memset(map, false, sizeof(map));
    int m;
    scanf("%d%d", &n, &m);
    if (n + m == 0) return false;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    return true;
}
int hungary()
{
    memset(link, -1, sizeof(link));
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(vst, false, sizeof(vst));
        if (dfs(i)) cnt++;
    }
    return cnt;
}
int main()
{
    while (init())
    {
        floyd();
        printf("%d\n", n - hungary());
    }
    return 0;
}
