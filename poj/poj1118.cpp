#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define N 700
#define PI acos(-1)
using namespace std;
int n, x[N], y[N];
bool okay(int a, int b, int c)
{
    return (y[b] - y[a]) * (x[c] - x[b]) == (y[c] - y[b]) * (x[b] - x[a]);
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                int s = 2;
                for (int k = j + 1; k <= n; ++k)
                    if (okay(i, j, k)) s++;
                res = max(res, s);
            }
        printf("%d\n", res);
    }
    return 0;
}
