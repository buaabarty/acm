#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 16
#define INF 1000000000
using namespace std;
int n, m;
int map[MAXN][MAXN], dat[MAXN];
bool init()
{
    scanf("%d%d", &n, &m);
    if (n + m == 0) return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &dat[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &map[i][j]);
    return true;
}
bool now[MAXN], res[MAXN], use[MAXN];
double minr = 1e20;
int d[MAXN];
int prim()
{
    for (int i = 1; i <= n; ++i)
    {
        use[i] = !now[i];
        d[i] = INF;
    }
    for (int i = 1; i <= n; ++i)
        if (!use[i]){
            d[i] = 0;
            break;
        }
    int s = 0;
    for (int i = 1; i <= m; ++i)
    {
        int a = INF, b;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (d[j] < a)){
                a = d[j], b = j;
            }
        use[b] = true;
        s += a;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (map[b][j] < d[j])) d[j] = map[b][j];
    }
    return s;
}
void dfs(int v, int k, int s)
{
    if (k == m){
        int temp = prim();
        if ((temp / (double)s) < minr){
            minr = temp / (double)s;
            memcpy(res, now, sizeof(now));
        }
        return;
    }
    if (v > n) return;
    now[v] = true;
    dfs(v + 1, k + 1, s + dat[v]);
    now[v] = false;
    dfs(v + 1, k, s);
}
int main()
{
    while (init())
    {
        memset(now, false, sizeof(now));
        minr = 1e20;
        dfs(1, 0, 0);
        bool flag = false;
        for (int i = 1; i <= n; ++i)
            if (res[i])
            {
                if (flag) printf(" ");
                flag = true;
                printf("%d", i);
            }
        printf("\n");
    }
    return 0;
}
