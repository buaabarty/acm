#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 200
using namespace std;
int t, n, m;
vector<int> map[MAX_N];
bool use[MAX_N];
int match[MAX_N];
bool hungary(int v)
{
    for (int i = 0, l = map[v].size(); i < l; i++)
    {
        int u = map[v][i];
        if (!use[u])
        {
            use[u] = true;
            int temp = match[u];
            match[u] = v;
            if (temp == 0 || hungary(temp)) return true;
            match[u] = temp;
        }
    }
    return false;
}

int calc()
{
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(use, false, sizeof(use));
        if (hungary(i)) cnt++;
    }
    return cnt;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) map[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x].push_back(y);
        }
        printf("%d\n", n - calc());
    }
    return 0;
}
