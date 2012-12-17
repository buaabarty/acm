#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
class data
{
public:
    int o;
    double x;
    bool operator < (const data a) const
    {
        if (x != a.x) return x < a.x;
        return o < a.o;
    }
}d[100010];
double iabs(double x)
{
    return (x > 0) ? x : -x;
}
int s[100010];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        d[i].o = i;
        d[i].x = iabs(((double)m + 1) / 2 - i * 1.0);
    }
    sort(d + 1, d + m + 1);
    for (int i = 1; i <= m; ++i)
        s[i] = d[i].o;
    s[0] = s[m];
    for (int i = 1; i <= n; ++i)
        printf("%d\n", s[i % m]);
    return 0;
}
