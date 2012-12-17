#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 1010
#define MAX_B 50
using namespace std;
int n, b, st, ed;//n个节点连向b个节点，其中b个节点可以连多条边
int dat[MAX_N][MAX_B];//邻接表
int c[MAX_B];//b个节点的边容量
vector<int> link[MAX_B];//b个节点的连接情况
bool use[MAX_B];//b个节点的访问情况
bool init()
{
    if (scanf("%d%d", &n, &b) == EOF) return false;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= b; ++j)
            scanf("%d", &dat[i][j]);
    for (int i = 1; i <= b; ++i)
        scanf("%d", &c[i]);
    return true;
}
bool dfs(int v)
{
    for (int i = st; i <= ed; ++i)
    {
        int a = dat[v][i];
        if (!use[a])
        {
            use[a] = true;
            if (link[a].size() < c[a])
            {
                link[a].push_back(v);
                return true;
            }
            else
            {
                for (int j = 0, k = link[a].size(); j < k; ++j)
                {
                    int u = link[a][j];
                    if (dfs(u))
                    {
                        link[a][j] = v;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool solve()
{
    for (int i = 1; i <= b; ++i)
        link[i].clear();
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(use, false, sizeof(use));
        if (dfs(i)) cnt++;
    }
    return cnt == n;
}
bool okay(int delta)
{
    for (int i = 1; i <= b - delta + 1; ++i)
    {
        st = i;
        ed = i + delta - 1;
        if (solve())
            return true;
    }
    return false;
}
int main()
{
    init();
    {
        int l = 1, r = b, mid;
        while (l < r)
        {
            if (l + 1 == r)
            {
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) / 2;
            if (okay(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
