#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#define N 1024
using namespace std;
int n, m, h, s[N];
long double C(int x, int y)
{
    long double r = 1;
    int j = 2;
    for (int i = x - y + 1; i <= x; ++i)
    {
        r *= (long double)i;
        if (j <= y)
        {
            r /= (long double)j;
            ++j;
        }
    }
    while (j <= y)
    {
        r /= (long double)j;
        ++j;
    }
    return r;
}
int main()
{
    while (~scanf("%d%d%d", &n, &m, &h))
    {
        for (int i = 1; i <= m; ++i) scanf("%d", &s[i]);
        int a = s[h], b = 0;
        for (int i = 1; i <= m; ++i) b += s[i];
        b -= a;
        if (a + b < n) printf("-1\n");
        else if (a + b == n)
        {
            if (a == 1) printf("0\n");
            else printf("1\n");
        }
        else
        {
            long double da = C(b, n - 1);
            long double db = C(a + b - 1, n - 1);
            long double res = 1.0;
            res = res - da / db;
            cout << setprecision(10) << res << endl;
        }
    }
    return 0;
}

