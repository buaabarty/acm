#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class vec
{
public:
    int x, y;
    bool operator < (const vec a) const
    {
        return (x * a.y - y * a.x < 0);
    }
    bool operator != (const vec a) const
    {
        if ((x == 0) && (y == 0)) return ((a.x != 0) || (a.y != 0));
        if ((a.x == 0) && (a.y == 0)) return ((x != 0) || (y != 0));
        return (x * a.y - y * a.x != 0);
    }
    bool operator == (const vec a) const
    {
        return (x * a.y - y * a.x == 0);
    }
    bool iszero()
    {
        return ((x == 0) && (y == 0));
    }
}v[40010];
int cnt;
int n, x[210], y[210];
bool okay[40010];
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &x[i], &y[i]);
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                ++cnt;
                v[cnt].x = x[i] - x[j];
                v[cnt].y = y[i] - y[j];
                if (v[cnt].iszero()) cnt--;
            }
        memset(okay, 1, sizeof(okay));
        for (int i = 1; i <= cnt; ++i) if (okay[i])
            for (int j = i + 1; j <= cnt; ++j)
                if (v[i] == v[j]) okay[j] = false;
        int res = 0;
        for (int i = 1; i <= cnt; ++i)
            res += okay[i];
        printf("%d\n", res);
    }
    return 0;
}
