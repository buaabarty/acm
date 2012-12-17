#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 128
using namespace std;
int t, n, m[MAXN], a[MAXN][MAXN], b[MAXN][MAXN];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int mind = INT_MAX, maxd = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &m[i]);
            for (int j = 1; j <= m[i]; ++j)
            {
                scanf("%d%d", &a[i][j], &b[i][j]);
                mind = min(a[i][j], mind);
                maxd = max(a[i][j], maxd);
            }
        }
        double res = 0;
        for (int i = mind; i <= maxd; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= n; ++j)
            {
                int min2 = 10000000;
                for (int k = 1; k <= m[j]; ++k)
                    if (a[j][k] >= i) min2 = min(min2, b[j][k]);
                sum += min2;
            }
            res = max(res, (double)i / (double)sum);
        }
        printf("%.3f\n", res);

    }
    return 0;
}
