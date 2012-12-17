#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> map[1050];
bool f[40][40], vst[1050];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int link[1050];
int n, m, k, x, y;
int ord(int x, int y)
{
    return (x - 1) * m + y;
}
bool dfs(int v)
{
    for (int i = 0, l = map[v].size(); i < l; i++)
    {
        int u = map[v][i];
        if (vst[u]) continue;
        vst[u] = true;
        if (link[u] == 0 || dfs(link[u]))
        {
            link[u] = v;
            return true;
        }
    }
    return false;
}
int main()
{
    while (cin >> n >> m >> k)
    {
        for (int i = 1; i <= n * m; i++)
            map[i].clear();
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                f[i][j] = true;
        for (int i = 1; i <= k; ++i)
        {
            scanf("%d%d", &y, &x);
            f[x][y] = false;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (!f[i][j]) continue;
                for (int k = 0; k < 4; ++k)
                {
                    int di = i + step[k][0];
                    int dj = j + step[k][1];
                    if (f[di][dj]) map[ord(i,j)].push_back(ord(di, dj));
                }
            }
        memset(vst, false, sizeof(vst));
        memset(link, 0, sizeof(link));
        int res = 0;
        for (int i = 1; i <= n * m; ++i)
        {
            if (dfs(i)) res++;
            memset(vst, false, sizeof(vst));
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (f[i][j]) res--;
        if (res == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
