#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 600
using namespace std;
vector<int> map[MAX_N];
int n, k, x, y, cnt;
int link[MAX_N];
bool vst[MAX_N];
bool dfs(int v)
{
    for  (int i = 0, l = map[v].size(); i < l; ++i)
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
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            map[i].clear();
        for (int i = 1; i <= k; ++i)
        {
            scanf("%d%d", &x, &y);
            map[x].push_back(y);
        }
        memset(link, 0, sizeof(link));
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            memset(vst, false, sizeof(vst));
            if (dfs(i)) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
