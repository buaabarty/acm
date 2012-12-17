#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 128
using namespace std;
bool map[MAXN][MAXN], temp[MAXN][MAXN], vst[MAXN], f[MAXN][MAXN];
int c[MAXN], a[MAXN], b[MAXN], st[MAXN], l[MAXN][MAXN];
int mind = MAXN, s = 0, rt[MAXN], k1[MAXN], k2[MAXN], lk1 = 0, lk2 = 0;
int n, x, cnt;
bool init()
{
    if (scanf("%d", &n) == EOF) return false;
    memset(temp, false, sizeof(temp));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        while (x != 0)
        {
            temp[i][x] = true;
            scanf("%d", &x);
        }
    }
    memset(map, false, sizeof(map));
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!(temp[i][j] && temp[j][i]))
            {
                map[i][j] = true;
                map[j][i] = true;
            }
    return true;
}

bool fill(int v, int color)
{
    c[v] = color;
    vst[v] = true;
    for (int i = 1; i <= n; ++i)
        if (map[v][i])
        {
            if (c[i] == color) return false;
            else if (c[i] == 0)
            {
                if (!fill(i, -color)) return false;
            }
        }
    return true;
}

bool make()
{
    memset(vst, false, sizeof(vst));
    memset(c, 0, sizeof(c));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!vst[i])
        {
            if (!fill(i, i)) return false;
            ++cnt;
            for (int j = 1; j <= n; ++j)
            {
                a[cnt] += (c[j] == i);
                b[cnt] += (c[j] == -i);
            }
            st[cnt] = i;
        }
    return true;
}

int nabs(int x)
{
    return (x > 0) ? x : -x;
}

void dp()
{
    memset(f, false, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = n; j >= 0; --j)
            for (int k = n; k >= 0; --k)
            {
                if (f[j][k]) continue;
                if (j >= a[i] && k >= b[i])
                {
                    if (f[j - a[i]][k - b[i]])
                    {
                        f[j][k] = true;
                        l[j][k] = i;
                    }
                }
                if (j >= b[i] && k >= a[i])
                {
                    if (f[j - b[i]][k - a[i]])
                    {
                        f[j][k] = true;
                        l[j][k] = -i;
                    }
                }
            }
    }
}

void print()
{
    memset(k1, 0, sizeof(k1));
    memset(k2, 0, sizeof(k2));
    lk1 = 0;
    lk2 = 0;
    for (int i = 1; i <= s; ++i)
        for (int j = 1; j <= n; ++j)
            if (rt[i] > 0)
            {
                if (c[j] == st[rt[i]]) k1[++lk1] = j;
                if (c[j] == -st[rt[i]]) k2[++lk2] = j;
            }
            else
            {
                if (c[j] == -st[-rt[i]]) k1[++lk1] = j;
                if (c[j] == st[-rt[i]]) k2[++lk2] = j;
            }
    for (int i = 1; i < lk1; ++i)
        for (int j = i + 1; j <= lk1; ++j)
            if (k1[i] > k1[j]) swap(k1[i], k1[j]);
    for (int i = 1; i < lk2; ++i)
        for (int j = i + 1; j <= lk2; ++j)
            if (k2[i] > k2[j]) swap(k2[i], k2[j]);
    printf("%d", lk1);
    for (int i = 1; i <= lk1; ++i)
        printf(" %d", k1[i]);
    printf("\n");
    printf("%d", lk2);
    for (int i = 1; i <= lk2; ++i)
        printf(" %d", k2[i]);
    printf("\n");
}

void doit()
{
    dp();
    mind = MAXN;
    s = 0;
    memset(rt, 0, sizeof(rt));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            if (f[i][j] && (i + j == n)) mind = min(mind, nabs(i - j));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            if (f[i][j] && (i + j == n) && nabs(i - j) == mind)
            {
                int x = i, y = j, dx, dy;
                while (x + y)
                {
                    rt[++s] = l[x][y];
                    if (l[x][y] > 0)
                    {
                        dx = a[l[x][y]];
                        dy = b[l[x][y]];
                    }
                    else
                    {
                        dx = b[nabs(l[x][y])];
                        dy = a[nabs(l[x][y])];
                    }
                    x -= dx;
                    y -= dy;
                }
                print();
                return;
            }
}

int main()
{
    init();
    if (!make()) printf("No solution\n");
    else doit();
    return 0;
}
