/*
ID:ybojan2
LANG:C++
TASK:frameup
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct rect{
    int x1, y1, x2, y2;
    bool app;
    void format(){app = false, x1 = 100, y1 = 100, x2 = 0, y2 = 0;}
    void update(int x, int y){
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
        app = true;
    }
}dat[52];
bool map[32][32];
int state[32][32], rd[32];
int n, m;
bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    char c;
    for (int i = 1; i <= 26; ++i)
        dat[i].format();
    for (int i = 1; i <= n; ++i)
    {
        scanf("\n");
        for (int j = 1; j <= m; ++j)
        {
            scanf("%c", &c);
            if (c != '.'){
                dat[c - 'A' + 1].update(i, j);
                state[i][j] = c - 'A' + 1;
            }
            else state[i][j] = 0;

        }
    }
    n = 26;
    m = 0;
    for (int i = 1; i <= n; ++i)
        if (dat[i].app) ++m;
    memset(map, false, sizeof(map));
    int x, y, x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i)
        if (dat[i].app){
            x, y, x1 = dat[i].x1, x2 = dat[i].x2, y1 = dat[i].y1, y2 = dat[i].y2;
            for (x = x1, y = y1; y <= y2; ++y)
                map[i][state[x][y]] = true;
            for (x = x1, y = y1; x <= x2; ++x)
                map[i][state[x][y]] = true;
            for (x = x2, y = y1; y <= y2; ++y)
                map[i][state[x][y]] = true;
            for (x = x1, y = y2; x <= x2; ++x)
                map[i][state[x][y]] = true;
        }
    for (int i = 1; i <= n; ++i)
        map[i][i] = false;
    memset(rd, 0, sizeof(rd));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (map[i][j]) ++rd[j];
    return true;
}
bool vst[32];
int res[32];
void dfs(int deep)
{
    if (deep == m){
        for (int i = 1; i <= deep; ++i)
            printf("%c", res[i] + 'A' - 1);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!vst[i] && (!rd[i]) && dat[i].app)
        {
            vst[i] = true;
            for (int j = 1; j <= n; ++j)
                if (map[i][j]) rd[j]--;
            res[deep + 1] = i;
            dfs(deep + 1);
            vst[i] = false;
            for (int j = 1; j <= n; ++j)
                if (map[i][j]) rd[j]++;
        }
}
void topsort()
{
    memset(vst, false, sizeof(vst));
    dfs(0);
}
int main()
{
    //freopen("frameup.in", "r", stdin);
    //freopen("frameup.out", "w", stdout);
    while (init())
        topsort();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
