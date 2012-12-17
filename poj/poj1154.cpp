#include <iostream>
#include <cstdio>
#include <cstring>
#define N 32
using namespace std;
int n, m, res;
int dat[N][N], step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vst[N];
char str[N];
void dfs(int x, int y, int deep)
{
    res = max(res, deep);
    for (int k = 0; k < 4; ++k)
    {
        int dx = x + step[k][0];
        int dy = y + step[k][1];
        if (dat[dx][dy] && !vst[dat[dx][dy]])
        {
            vst[dat[dx][dy]] = true;
            dfs(dx, dy, deep + 1);
            vst[dat[dx][dy]] = false;
        }
    }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            for (int j = 1; j <= m; ++j)
                dat[i][j] = str[j - 1] - 'A' + 1;
        }
        memset(vst, false, sizeof(vst));
        res = 0;
        vst[dat[1][1]] = true;
        dfs(1, 1, 1);
        printf("%d\n", res);
    }
    return 0;
}
