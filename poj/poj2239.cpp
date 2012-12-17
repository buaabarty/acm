#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, t, p, q;
vector<int> map[310];
bool vst[310];
int link[310];
bool dfs(int v)
{
    for (int i = 0, l = map[v].size(); i < l; i++)
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
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= 300; ++i)
            map[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &t);
            for (int j = 1; j <= t; ++j)
            {
                scanf("%d%d", &p, &q);
                map[(p - 1) * 12 + q].push_back(i);
            }
        }
        int cnt = 0;
        memset(link, 0, sizeof(link));
        for (int i = 1; i <= 300; ++i)
        {
            if (dfs(i)) cnt++;
            memset(vst, false, sizeof(vst));
        }
        cout << cnt << endl;
    }
    return 0;
}
