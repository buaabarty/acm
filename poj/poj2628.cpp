#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#define PI acos(-1)
#define N 64
#define EPS 1e-6
using namespace std;
double tt(int x, int y, int n)
{
    double theta = 2.0*PI / n;
    if (x > y) swap(x, y);
    theta *= (y - x);
    if (theta > PI) theta = 2.0 * PI - theta;
    return theta;
}
bool okay(int x, int y, int z, int n)
{
    double ta = tt(x, y, n);
    double tb = tt(x, z, n);
    double tc = tt(y, z, n);
    if (tc < ta) swap(ta, tc);
    if (tc < tb) swap(tb, tc);
    return (ta + tb > PI + EPS);
}
int main()
{
    int n, h[N];
    while (scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        int res = INT_MAX;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                    for (int k = j + 1; k <= n; ++k)
                        if (okay(i, j, k, n))
                        {
                            int t = min(min(h[i], h[j]), h[k]);
                            res = min(res, h[i] + h[j] + h[k] - t * 3);
                        }
        printf("%d\n", res);
    }
    return 0;
}
