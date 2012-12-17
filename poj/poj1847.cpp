#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 128
#define MAX_INT 1000000000
using namespace std;
int map[MAXN][MAXN], n, a, b, k, x;
void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            map[i][j] = MAX_INT;
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d", &x);
            if (j == 1) map[i][x] = 0;
            else map[i][x] = 1;
        }
    }
    floyd();
    if (map[a][b] == MAX_INT) cout << -1 << endl;
    else cout << map[a][b] << endl;
    return 0;
}
