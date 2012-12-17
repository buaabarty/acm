#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 128
#define MAXM 32768
#define INF 1e15
using namespace std;
double g[MAXN][MAXN];
double res;
int n, m;
template <class T>
void update(T& o, const T& x)
{
    if (o > x) o = x;
}
double sqr(double x)
{
    return x * x;
}
double dist(double xa, double ya, double xb, double yb)
{
    return sqrt(sqr(xa - xb) + sqr(ya - yb));
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%.2f ", g[i][j]);
        printf("\n");
    }
}
bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    double x[MAXN], y[MAXN];
    int a, b;
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = INF;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        g[a][b] = min(g[a][b], dist(x[a], y[a], x[b], y[b]));
    }
    //print_map();
    return true;
}
bool vst[MAXN];
void dfs(int v)
{
    vst[v] = true;
    for (int i = 1; i <= n; ++i)
        if (!vst[i] && g[v][i] != INF) dfs(i);
}
bool possible(int v)
{
    memset(vst, false, sizeof(vst));
    dfs(v);
    for (int i = 1; i <= n; ++i)
        if (i != v && !vst[i]) return false;
    return true;
}
int pre[MAXN];
bool del[MAXN];
void solve(int v)//根为v
{
    res = 0;
    int num = n;
    memset(del, false, sizeof(del));
    while(1)
    {
        int i;
        //更新pre数组
        for (i = 1; i <= n; ++i)
        {
            if (del[i] || i == v) continue;
            pre[i] = i;
            g[i][i] = INF;
            for (int j = 1; j <= n; ++j)
            {
                if (del[j]) continue;
                if (g[j][i] < g[pre[i]][i])
                    pre[i] = j;
            }
        }
        for (i = 1; i <= n; ++i)
        {
            //找环
            if (del[i] || i == v) continue;
            int j = i;
            memset(vst, 0, sizeof(vst));
            while (!vst[j] && j != v)
            {
                vst[j] = true;
                j = pre[j];
            }
            if (j == v) continue;
            i = j;
            //更新res，有向环缩点
            res += g[pre[i]][i];
            for(j = pre[i]; j != i; j = pre[j])
            {
                res += g[pre[j]][j];
                del[j] = true;
            }
            for(j = 1; j <= n; ++j)
            {
                if(del[j]) continue;
                if(g[j][i] != INF)
                    g[j][i] -= g[pre[i]][i];
            }
            //更新缩点以后的有向环和其他点的边权
            for(j = pre[i]; j != i; j = pre[j])
            {
                for(int k = 1; k <= n; ++k)
                {
                    if(del[k])continue;
                    g[i][k] = min(g[i][k], g[j][k]);
                    if(g[k][j] != INF)
                        g[k][i] = min(g[k][i], g[k][j] - g[pre[j]][j]);
                }
            }
            //完成缩点
            for(j = pre[i]; j != i; j = pre[j])
            {
                del[j] = true;
            }
            break;
        }
        //不存在有向环时，停止循环，得出res最终值
        if(i > n){
            for(int i = 1; i <= n; ++i)
            {
                if(del[i] || i == v) continue;
                res += g[pre[i]][i];
            }
            break;
        }
    }
}
int main()
{
    while (init())
    {
        if (!possible(1)) printf("poor snoopy\n");
        else
        {
            solve(1);
            printf("%.2f\n", res);
        }
    }
    return 0;
}
