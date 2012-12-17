#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 128
using namespace std;
int n, m, s;
bool map[MAX_N][MAX_N];
bool init()
{
    scanf("%d", &n);
    if (n == 0) return false;
    scanf("%d%d", &m, &s);
    memset(map, false, sizeof(map));
    for (int i = 1; i <= s; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (b * c != 0) map[b][c] = true;
    }
    n--; m--;
/*    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d ", map[i][j]);
        printf("\n");
    }*/
    return true;
}
int link[MAX_N];
bool use[MAX_N];
bool dfs(int v)
{
    for (int i = 1; i <= m; ++i)
        if (!use[i] && map[v][i])
        {
            use[i] = true;
            if ((link[i] == -1) || (dfs(link[i])))
            {
                link[i] = v;
                return true;
            }
        }
    return false;
}
int hungary()
{
    memset(link, -1, sizeof(link));
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(use, false, sizeof(use));
        if (dfs(i)) cnt++;
    }
    /*for (int i = 1; i <= m; ++i)
        printf("%d ", link[i]);
    printf("\n");*/
    return cnt;
}
int main()
{
    while (init())
    {
        cout << hungary() << endl;
    }
    return 0;
}
