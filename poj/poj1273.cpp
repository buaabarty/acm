#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAX_N 210
using namespace std;
int n, m, g[MAX_N][MAX_N];
bool init()
{
    if ((scanf("%d%d", &m, &n)) == EOF) return false;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] += c;
    }
    return true;
}

/*
Dinic 算法部分
*/
int f[MAX_N][MAX_N], pre[MAX_N];
bool b[MAX_N];
int dinic(int s, int t)
{
    memset(f, 0, sizeof(f));
    memset(b, false, sizeof(false));
    int ans = 0;
    while (1)
    {
        queue<int> q;
        fill(pre, pre + n + 2, -1);
        fill(b, b + n + 2, 0);
        q.push(s);
        b[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            if (x == t) break;
            for (int i = 1; i <= n; ++i)
            {
                if (!b[i] && f[x][i] < g[x][i])
                {
                    pre[i] = x;
                    b[i] = 1;
                    q.push(i);
                }
            }
            q.pop();
        }
        if (pre[t] == -1) break;
        for (int i = 1; i <= n; ++i)
        {
            if (f[i][t] < g[i][t] && (i == s || pre[i] != -1))
            {
                int v, low = g[i][t] - f[i][t];
                pre[t] = i;
                for (v = t; pre[v] != -1; v = pre[v])
                     low=low<g[pre[v]][v]-f[pre[v]][v]?low:g[pre[v]][v]-f[pre[v]][v];
                if (low == 0) continue;
                for (v = t; pre[v] != -1; v = pre[v])
                {
                    f[pre[v]][v] += low;
                    f[v][pre[v]] -= low;
                }
                ans += low;
            }
        }
    }
    return ans;
}

/*
sap+gap 算法部分
*/


int main()
{
    while (init()) printf("%d\n", dinic(1, n));
    return 0;
}
