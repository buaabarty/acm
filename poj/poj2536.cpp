#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
vector<int> map[200];
int n, m, s, v;
bool vst[200];
int link[200];
class POINT{
    public:
        double x, y;
        double sqr(double a)
        {
            return a * a;
        }
        double dist(POINT k, double v)
        {
            return sqrt(sqr(x - k.x) + sqr(y - k.y)) / v;
        }
}a[200], b[200];
bool dfs(int v)
{
    for (int i = 0, l = map[v].size(); i < l; ++i)
    {
        int u = map[v][i];
        if (!vst[u])
        {
            vst[u] = true;
            if (link[u] == 0 || dfs(link[u]))
            {
                link[u] = v;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while (scanf("%d%d%d%d", &n, &m, &s, &v) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%lf%lf", &a[i].x, &a[i].y);
        for (int i = 1; i <= m; ++i)
            scanf("%lf%lf", &b[i].x, &b[i].y);
        for (int i = 1; i <= 100; ++i)
            map[i].clear();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i].dist(b[j], (double)v) <= s)
                {
                    map[i].push_back(j);
                    //printf("%d %d\n", i, j);
                }
        memset(link, 0, sizeof(link));
        int cnt = 0;
        for (int i = 1; i <= 100; ++i)
        {
            memset(vst, false, sizeof(vst));
            if (dfs(i)) cnt++;
        }
        printf("%d\n", n - cnt);
    }
    return 0;
}
