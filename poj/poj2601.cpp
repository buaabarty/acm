#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 8192
using namespace std;
double a[MAXN], c[MAXN];
bool get[MAXN];
int n;
bool okay(double x)
{
    a[1] = x;
    for (int i = 2; i <= n; ++i)
        a[i] = 2 * a[i - 1] - a[i - 2] + c[i - 1];
    return (a[n + 1] >= (2 * a[n] - a[n - 1] + 2 * c[n]));
}
int main()
{
    memset(get, false, sizeof(get));
    scanf("%d", &n);
    scanf("%lf%lf", &a[0], &a[n + 1]);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &c[i]);
    double l = 0, r = 1e10;
    while (fabs(l - r) > 1e-4)
    {
        if (okay((l + r) / 2.0)) l = (l + r) / 2.0;
        else r = (l + r) / 2.0;
    }
    printf("%.2f\n",  a[1]);
    return 0;
}
