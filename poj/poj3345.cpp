#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <sstream>
#define L 1024
#define N 512
#define M 65536
#define INF 1000000000
using namespace std;
struct edge
{
    int v, next;
}e[M];
int n, m, p[N], eid;
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
char str[L], name[N][L], x;
int d[N], a, b, cnt = 0;
int getid(char *s)
{
    for (int i = 1; i <= cnt; ++i)
        if (strcmp(s, name[i]) == 0) return i;
    strcpy(name[++cnt], s);
    return cnt;
}
void print_map()
{
    for (int i = 1; i <= n + 1; ++i)
    {
        printf("%d: ", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        puts("");
    }
}
void update(int &x, int y)
{
    if (y < x) x = y;
}
int dp[N][N], s[N];
bool isroot[N], vst[N];
void dfs(int v)
{
    s[v] = 1; dp[v][0] = 0;
    for (int i = 1; i <= n + 1; ++i) dp[v][i] = INF;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            int now = e[i].v;
            dfs(now);
            s[v] += s[now];
        }
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
            //printf("%d %d\n", v, e[i].v);
        int now = e[i].v;
        for (int j = n; j >= 1; --j)
            for (int k = 1; k <= j; ++k)
                update(dp[v][j], dp[now][k] + dp[v][j - k]);
    }
//    printf("%d:sum[%d]\n", v, s[v]);
//    for (int j = 0; j <= m; ++j)
//        printf("%15d", dp[v][j]);
//    puts("");
    update(dp[v][s[v]], d[v]);
//    for (int j = 0; j <= m; ++j)
//        printf("%15d", dp[v][j]);
//    puts("");
//    vst[v] = false;
}
int rd[N];
int main()
{
    //freopen("g.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    while (gets(str), (str[0] != '#'))
    {
        memset(rd, 0, sizeof(rd));
        memset(name, 0, sizeof(name));
        memset(isroot, 1, sizeof(isroot));
        cnt = 0; mapinit();
        sscanf(str, "%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s%d", str, &d[i]);
            a = getid(str);
            gets(str);
            stringstream ss(str);
            while (ss >> str)
            {
                b = getid(str);
                insert(a, b);
                isroot[b] = false;
                rd[b]++;
            }
        }
        for (int i = 1; i <= n; ++i) printf("%3d", rd[i]);puts("");
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        memset(vst, 0, sizeof(vst));
        d[n + 1] = INF;
        int it = 0;
        for (int i = 1; i <= n; ++i)
            if (isroot[i])
            {
                printf("%d ", d[i]);
                insert(n + 1, i);
                it++;
            }
        printf("%d\n", it);
        dfs(n + 1);
        int res = INF;
        for (int i = m; i <= n; ++i)
        {
            printf("%5d", dp[n + 1][i]);
            update(res, dp[n + 1][i]);
        }
        print_map();
        printf("ANS%d\n", res);
        printf("%d\n", cnt);
        printf("%d\n", dp[n + 1][m]);
        for (int i = 1; i <= n; ++i)
            if (isroot[i]) printf("%d %d %d\n", i, d[i], s[i]);
//        print_map();
    }
    return 0;
}
