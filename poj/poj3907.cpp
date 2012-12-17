#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 1000000
using namespace std;
double x[MAXN], y[MAXN];
int n;
int main()
{
    while(scanf("%d", &n))
    {
        if (!n) break;
        for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
        double s = 0;
        x[n + 1] = x[1];
        y[n + 1] = y[1];
        for (int i = 1; i <= n; ++i)
            s = s + x[i] * y[i + 1] - x[i + 1] * y[i];
        printf("%d\n", (int)(fabs(s / 2.0) + 0.5));
    }
    return 0;
}
