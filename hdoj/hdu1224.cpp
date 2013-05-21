#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
using namespace std;
int n, d[N], f[N], pre[N], m, res[N], rl;
bool map[N][N];
int main()
{
    //freopen("input.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &d[i]);
        scanf("%d", &m);
        int x, y;
        memset(map, false, sizeof(map));
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = true;
        }
        memset(f, -1, sizeof(f));
        memset(pre, -1, sizeof(pre));
        f[1] = 0;
        d[n + 1] = 0;
        for (int i = 2; i <= n + 1; ++i)
            for (int j = 1; j < i; ++j)
                if ((f[j] != -1) && (map[j][i]))
                {
                    if (f[j] + d[i] > f[i])
                    {
                        f[i] = f[j] + d[i];
                        pre[i] = j;
                    }
                }
        printf("CASE %d#\npoints : %d\ncircuit : 1", ca, f[n + 1]);
        if (n > 1)
        {
            rl = 0;
            int i = n + 1;
            while (i > 0)
            {
                res[++rl] = i;
                i = pre[i];
            }
            for (int i = rl - 1; i > 1; --i)
                printf("->%d", res[i]);
            printf("->1");
        }
        printf("\n");
        if (ca != T) printf("\n");
//        system("pause");
    }
    return 0;
}
