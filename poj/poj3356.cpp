#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 1024
using namespace std;
string a, b;
int n, m, f[MAXN][MAXN];
int main()
{
    while (cin >> n >> a >> m >> b)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (a[i - 1] == b[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        printf("%d\n", max(n, m) - f[n][m]);
    }
    return 0;
}
