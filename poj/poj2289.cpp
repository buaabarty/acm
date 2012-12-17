#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <vector>
#define L 32
#define N 1024
#define M 512
using namespace std;
typedef struct
{
    int v, next;
}edge;
const int MAXN = 2048;
const int MAXM = 10000000;
edge e[MAXM];
int p[MAXN], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, m;//n个节点连向m个节点，其中m个节点可以连多条边
int c[M];//m个节点的边容量
vector<int> link[M];//m个节点的连接情况
bool use[M];//m个节点的访问情况
bool dfs(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int a = e[i].v;
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
int solve()
{
    for (int i = 1; i <= m; ++i)
        link[i].clear();
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(use, false, sizeof(use));
        if (dfs(i)) cnt++;
    }
    return cnt;
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: ", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        puts("");
    }
}
vector<int> cts[N];
char str[L];
bool okay(int limit)
{
    mapinit();
    for (int i = 1; i <= m; ++i) c[i] = limit;
    for (int i = 1; i <= n; ++i)
        for (int j = 0, s = cts[i].size(); j < s; ++j)
            insert(i, cts[i][j] + 1);
    return solve() == n;
}
int main()
{
    while (scanf("%d%d", &n, &m), (n + m))
    {
        for (int i = 1; i <= n; ++i)
        {
            int x;
            char c;
            cts[i].clear();
            scanf("%s", str);
            while (scanf("%d%c", &x, &c))
            {
                cts[i].push_back(x);
                if (c == '\n') break;
            }
        }
        int left = 0, right = n, mid;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (!okay(left)) left = right;
                break;
            }
            mid = (left + right) / 2;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        printf("%d\n", left);
    }
    return 0;
}
