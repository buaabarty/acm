#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
using namespace std;
int n, x;
bool map[N][N], vst[N];
int main()
{
    scanf("%d", &n);
    memset(map, false, sizeof(map));
    for (int i = 1; i <= n; ++i)
    {
        while (scanf("%d", &x), x) map[i][x] = true;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] |= (map[i][k] & map[k][j]);
    int cnt = n;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!vst[j] && map[i][j])
            {
                vst[j] = true;
                --cnt;
            }
    printf("%d\n", cnt);
    return 0;
}
