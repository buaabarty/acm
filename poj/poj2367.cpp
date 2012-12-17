#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 128
using namespace std;
bool map[MAXN][MAXN];
int rd[MAXN];
int n, x;
bool init()
{
    if (scanf("%d", &n) == EOF) return false;
    memset(map, false, sizeof(map));
    for (int i = 1; i <= n; ++i)
        while (scanf("%d", &x), x) map[i][x] = true;
    for (int i = 1; i <= n; ++i)
        map[i][i] = false;
    memset(rd, 0, sizeof(rd));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (map[i][j]) ++rd[j];
    return true;
}
bool vst[MAXN];
int res[MAXN];
void topsort()
{
    memset(vst, false, sizeof(vst));
    for (int t = 1; t <= n; ++t)
        for (int i = 1; i <= n; ++i)
            if ((!rd[i]) && !vst[i])
            {
                vst[i] = true;
                for (int j = 1; j <= n; ++j)
                    if (map[i][j]) --rd[j];
                printf("%d", i);
                if (t == n) printf("\n");
                else printf(" ");
                break;
            }
}
int main()
{
    while (init())
        topsort();
    return 0;
}
