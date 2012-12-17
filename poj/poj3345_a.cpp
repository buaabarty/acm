#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <sstream>
#include <cstdlib>
#define L 1024
#define N 256
#define M 65536
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
char str[L], x;
string name[N];
int d[N], a, b, cnt = 0;
int getid(string str)
{
    for (int i = 1; i <= cnt; ++i)
        if (name[i] == str) return i;
    name[++cnt] = str;
    return cnt;
}
void update(int &x, int y)
{
    if (y < x) x = y;
}
int dp[N][N], s[N];
bool vst[N], isroot[N];
void dfs(int v)
{
    dp[v][0] = 0;
    for (int i = 1; i <= m; ++i) dp[v][i] = INT_MAX / 2;
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            int now = e[i].v;
            dfs(now);
            s[v] += s[now];
            for (int j = m; j > 0; --j)
                for (int k = 1; k <= j; ++k)
                    update(dp[v][j], dp[now][k] + dp[v][j - k]);
        }
    s[v]++;
    for (int j = 0; j <= s[v]; ++j) update(dp[v][j], d[v]);
    vst[v] = false;
}
int main()
{
    while (gets(str), (str[0] != '#'))
    {
        memset(isroot, 1, sizeof(isroot));
        cnt = 0; mapinit();
        sscanf(str, "%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            int temp;
            scanf("%s%d", str, &temp);
            a = getid(string(str));
            d[a] = temp;
            gets(str);
            stringstream ss(str);
            string nm;
            while (ss >> nm)
            {
                b = getid(nm);
                insert(a, b);
                isroot[b] = false;
            }
        }
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        memset(vst, 0, sizeof(vst));
        d[0] = INT_MAX / 2;
        for (int i = 1; i <= n; ++i)
            if (isroot[i]) insert(0, i);
        dfs(0);
        printf("%d\n", dp[0][m]);
    }
    return 0;
}
