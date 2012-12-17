#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int fa[MAXN], s[MAXN];
int father(int v)
{
    if (fa[v] != v)
    {
        int temp = father(fa[v]);
        s[v] ^= s[fa[v]];
        fa[v] = temp;
    }
    return fa[v];
}
int q, n, p1, p2, x, y, z, fx, fy, color[MAXN];
char str[10];
bool app[MAXN], res[MAXN];
int dat[MAXN][2], cnt = 0, f[MAXN][MAXN], l[MAXN][MAXN], num[MAXN];
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("ans.txt", "w", stdout);
    while (scanf("%d%d%d", &q, &p1, &p2), (q + p1 + p2))
    {
        n = p1 + p2;
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            s[i] = 0;
        }
        for (int i = 1; i <= q; ++i)
        {
            scanf("%d%d%s", &x, &y, str);
            z = (str[0] == 'n');
            fx = father(x); fy = father(y);
            if (fx != fy)
            {
                fa[fx] = fy;
                s[fx] = s[x] ^ s[y] ^ z;
            }
        }
        for (int i = 1; i <= n; ++i) fa[i] = father(i);
        memset(app, false, sizeof(app));
        for (int i = 1; i <= n; ++i)
            app[fa[i]] = true;
        cnt = 0;
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            if (app[i])
            {
                ++cnt;
                num[cnt] = i;
                for (int j = 1; j <= n; ++j)
                    if (fa[j] == i) ++dat[cnt][s[j]];
            }
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(l));
        f[0][0] = 1;
        for (int i = 1; i <= cnt; ++i)
        {
            for (int j = p1; j >= 0; --j)
                for (int k = p2; k >= 0; --k)
                {
                    if ((j >= dat[i][0]) && (k >= dat[i][1]) && (f[j - dat[i][0]][k - dat[i][1]]))
                    {
                        f[j][k] += f[j - dat[i][0]][k - dat[i][1]];
                        l[j][k] = 0;
                    }
                    if ((j >= dat[i][1]) && (k >= dat[i][0]) && (f[j - dat[i][1]][k - dat[i][0]]))
                    {
                        f[j][k] += f[j - dat[i][1]][k - dat[i][0]];
                        l[j][k] = 1;
                    }
                }
        }
        if (f[p1][p2] != 1) printf("no\n");
        else
        {
            memset(f, 0, sizeof(f));
            memset(l, 0, sizeof(l));
            f[0][0] = 1;
            for (int i = 1; i <= cnt; ++i)
            {
                for (int j = p1; j >= 0; --j)
                    for (int k = p2; k >= 0; --k)
                    {
                        if (f[j][k]) continue;
                        if ((j >= dat[i][0]) && (k >= dat[i][1]) && (f[j - dat[i][0]][k - dat[i][1]]))
                        {
                            f[j][k] += f[j - dat[i][0]][k - dat[i][1]];
                            l[j][k] = 0;
                            continue;
                        }
                        if ((j >= dat[i][1]) && (k >= dat[i][0]) && (f[j - dat[i][1]][k - dat[i][0]]))
                        {
                            f[j][k] += f[j - dat[i][1]][k - dat[i][0]];
                            l[j][k] = 1;
                            continue;
                        }
                    }
            }
            memset(res, false, sizeof(res));
            int x = p1, y = p2;
            for (int i = cnt; i >= 1; --i)
            {
                for (int j = 1; j <= n; ++j)
                        if ((fa[j] == num[i]) && (s[j] == l[x][y])) res[j] = true;
                if (l[x][y])
                {
                    x -= dat[i][1]; y -= dat[i][0];
                }
                else
                {
                    x -= dat[i][0]; y -= dat[i][1];
                }
            }
            for (int i = 1; i <= n; ++i)
                if (res[i]) printf("%d\n", i);
            printf("end\n");
        }
    }
    return 0;
}
