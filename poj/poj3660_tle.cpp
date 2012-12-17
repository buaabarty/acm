#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 128
using namespace std;
bool map[MAXN][MAXN];
int rd[MAXN];
int n, x, m, y;
bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    memset(map, false, sizeof(map));
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    memset(rd, 0, sizeof(rd));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (map[i][j]) ++rd[j];
    return true;
}
bool vst[MAXN];
int res[MAXN];
bool topsort()
{
    int cnt = 0;
    memset(vst, false, sizeof(vst));
    for (int t = 1; t <= n; ++t)
        for (int i = 1; i <= n; ++i)
            if ((!rd[i]) && !vst[i])
            {
                cnt++;
                vst[i] = true;
                for (int j = 1; j <= n; ++j)
                    if (map[i][j]) --rd[j];
                break;
            }
    return (cnt == n);
}
int dat[MAXN], now[MAXN];
bool s[MAXN];
void dfs(int deep)
{
    if (deep == n){
        if (dat[1] == 0){
            for (int i = 1; i <= n; ++i)
                dat[now[i]] = i;
        }
        else{
            for (int i = 1; i <= n; ++i)
                if (dat[now[i]] != i) s[now[i]] = false;
        }
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!vst[i] && (!rd[i])){
            vst[i] = true;
            for (int j = 1; j <= n; ++j)
                if (map[i][j]) --rd[j];
            now[deep + 1] = i;
            dfs(deep + 1);
            vst[i] = false;
            for (int j = 1; j <= n; ++j)
                if (map[i][j]) ++rd[j];
        }
}
int main()
{
    while (init())
    {
        if (!topsort()) printf("0\n");
        else{
            memset(s, true, sizeof(s));
            memset(vst, false, sizeof(vst));
            memset(dat, 0, sizeof(dat));
            dfs(0);
            int cnt = 0;
            for (int i = 1; i <= n; ++i) cnt += s[i];
            printf("%d\n", cnt);
        }
    }
    return 0;
}
