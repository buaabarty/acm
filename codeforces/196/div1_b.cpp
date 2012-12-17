#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, a[110], b[110];
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i <= m; ++i)
        scanf("%d", &b[i]);
    if (n > m) printf("%sInfinity\n", (a[0] * b[0] > 0) ? "" : "-");
    else if (n < m) printf("0/1\n");
    else
    {
        int f = (a[0] * b[0] > 0) ? 1 : -1;
        a[0] = iabs(a[0]);
        b[0] = iabs(b[0]);
        int g = gcd(a[0], b[0]);
        a[0] = a[0] * f / g;
        b[0] = b[0] / g;
        printf("%d/%d\n", a[0], b[0]);
    }
    return 0;
}
