#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
class data
{
public:
    int x, y;
    data(int _x, int _y)
    {
        x = _x, y = _y;
    }
    data(){}
    bool operator < (const data a) const
    {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
}d[50010];
int main()
{
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &d[i].x, &d[i].y);
        sort(d, d + n);
        int now = d[n - 1].y, cnt = 1;
        for (int i = n - 2; i >= 0; --i)
            if (d[i].y > now)
            {
                now = d[i].y;
                ++cnt;
            }
        printf("%d\n", cnt);
    }
    return 0;
}
