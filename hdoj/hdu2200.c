#include <stdio.h>
#include <math.h>
double frac(int x)
{
    double r = 1;
    while (x > 1) r *= x--;
    return r;
}
double c(int x, int y)
{
    return frac(x) / (frac(y) * frac(x - y));
}
int main()
{
    int n, i;
    double res = 0;
    while (~scanf("%d", &n))
    {
        res = 0;
        for (i = 2; i <= n; ++i)
            res = res + c(n, i) * (i - 1);
        printf("%.0f\n", res);
    }
    return 0;
}
