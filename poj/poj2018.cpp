#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 100010
using namespace std;
int n, f, num[N];
double h[N], s[N];
bool okay(double limit)
{
    s[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        h[i] = (num[i] - limit);
        s[i] = s[i - 1] + h[i];
    }
    double nows = s[f];
    if (nows >= 0) return true;
    for (int i = f + 1; i <= n; ++i)
    {
        if (nows + h[i] < s[i] - s[i - f]) nows = s[i] - s[i - f];
        else nows += h[i];
        if (nows >= 0) return true;
    }
    return false;
}
int main()
{
    while (~scanf("%d%d", &n, &f))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        double left = 0, right = 2000;
        while (fabs(left - right) > 1e-5)
        {
            if (okay((left + right) / 2)) left = (left + right) / 2;
            else right = (left + right) / 2;
        }
        printf("%d\n", (int)(left * 1000 + 1e-2));
    }
    return 0;
}
