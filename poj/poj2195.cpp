#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX_N 110
using namespace std;
int map[MAX_N][MAX_N];
int a, b, n;
int lx[MAX_N], ly[MAX_N];
bool vx[MAX_N], vy[MAX_N];
int match[MAX_N];
char c;
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(int x1, int y1, int x2, int y2)
{
    return iabs(x2 - x1) + iabs(y2 - y1);
}
bool init()
{
    memset(map, 0, sizeof(map));
    int x1[MAX_N], y1[MAX_N], x2[MAX_N], y2[MAX_N], t1 = 0, t2 = 0;
    cin >> a >> b;
    if (a + b == 0) return false;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
        {
            cin >> c;
            if (c == 'm')
            {
                x1[++t1] = i;
                y1[t1] = j;
            }
            else if (c == 'H')
            {
                x2[++t2] = i;
                y2[t2] = j;
            }
        }
    for (int i = 1; i <= t1; ++i)
        for (int j = 1; j <= t2; ++j)
            map[i][j] = dist(x1[i], y1[i], x2[j], y2[j]);
    n = max(t1, t2);
    return true;
}
bool path(int x)
{
    vx[x] = true;
    for (int y = 1; y <= n; ++y)
        if (!vy[y] && lx[x] + ly[y] == map[x][y])
        {
            vy[y] = true;
            if (match[y] == -1 || path(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    return false;
}
int bestmatch(bool maxsum)
{
    int i, j;
    if (!maxsum)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = -map[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        lx[i] = -0x1fffffff;
        ly[i] = 0;
        for (int j = 1; j <= n; ++j)
            lx[i] = max(lx[i], map[i][j]);
    }
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; ++i)
        while (1)
        {
            memset(vx, false, sizeof(vx));
            memset(vy, false, sizeof(vy));
            if (path(i)) break;
            int dx = 0x7fffffff;
            for (int i = 1; i <= n; ++i)
                if (vx[i])
                    for (int j = 1; j <= n; ++j)
                        if (!vy[j])
                            dx = min(lx[i] + ly[j] - map[i][j], dx);
            for (int i = 1; i <= n; ++i)
            {
                if (vx[i]) lx[i] -= dx;
                if (vy[i]) ly[i] += dx;
            }
        }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += map[match[i]][i];
    if (!maxsum)
    {
        sum = -sum;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = -map[i][j];
    }
    return sum;
}
int main()
{
    while (init())
        cout << bestmatch(false) << endl;
    return 0;
}
