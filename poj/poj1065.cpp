#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
using namespace std;
struct node
{
    int x, y;
}d[N];
bool cmp(node a, node b)
{
    return (a.x < b.x) || ((a.x == b.x) && (a.y > b.y));
}
int f[N], n;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &d[i].x, &d[i].y);
        sort(d, d + n, cmp);
        for (int i = 0; i < n; ++i)
            printf("%d %d\n", d[i].x, d[i].y);
        memset(f, 0, sizeof(f));
        int now = 0, res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (d[i].x == d[i - 1].x) res++;
            else if (d[i].y > d[i - 1].y) res++;
            else res = 0;
            res = max(res, now);
        }
        printf("%d\n", res);
    }
    return 0;
}
