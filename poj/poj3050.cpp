#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 16
#define MAXM 1000000
using namespace std;
int dat[MAXN][MAXN], use[MAXM], vst[MAXN][MAXN], step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool inside(int x)
{
    return (x >= 1) && (x <= 5);
}
void dfs(int x, int y, int deep, int sum)
{
    if (deep == 5)
    {
        use[sum] = true;
        return;
    }
    for (int k = 0; k < 4; ++k)
    {
        int dx = x + step[k][0], dy = y + step[k][1];
        if (inside(dx) && inside(dy))
        {
            vst[dx][dy] = true;
            dfs(dx, dy, deep + 1, sum * 10 + dat[dx][dy]);
            vst[dx][dy] = false;
        }
    }
}
int main()
{
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            scanf("%d", &dat[i][j]);
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
        {
            memset(vst, false, sizeof(vst));
            vst[i][j] = true;
            dfs(i, j, 0, dat[i][j]);
        }
    int res = 0;
    for (int i = 0; i < 1000000; ++i)
        if (use[i]) ++res;
    printf("%d\n", res);
    return 0;
}
