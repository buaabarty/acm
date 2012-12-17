#include <cstdio>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#define eps 1e-6
#define inf 1e20
#define N 128
using namespace std;
double map[N][N];//邻接矩阵
int n;//最大节点数
double lx[N], ly[N];//标号
bool vx[N], vy[N];//记录是否访问
int match[N], res[N];//存储匹配结果
int sqr(int x)
{
    return x * x;
}
double fsame(double a, double b)
{
    return fabs(a - b) < eps;
}
bool path(int x)
{
    vx[x] = true;
    for (int y = 1; y <= n; ++y)
        if (!vy[y] && fsame(lx[x] + ly[y], map[x][y]))
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
double bestmatch(bool maxsum)//maxsum为真则为求最大值，为假则求最小值
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
        lx[i] = -inf;
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
            double dx = inf;
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
    double sum = 0;
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
int ax[N], ay[N], bx[N], by[N];
int main()
{
    while (~scanf("%d", &n))
    {
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; ++i) scanf("%d%d", &ax[i], &ay[i]);
        for (int i = 1; i <= n; ++i) scanf("%d%d", &bx[i], &by[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = sqrt((double)(sqr(ax[i] - bx[j]) + sqr(ay[i] - by[j])));
        bestmatch(false);
        for (int i = 1; i <= n; ++i)
            res[match[i]] = i;
        for (int i = 1; i <= n; ++i) printf("%d\n", res[i]);
    }
    return 0;
}
