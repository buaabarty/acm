#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;
int fa[N], n, a, b, c, cnt[N];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
int A(int x, int y)
{
    if (x < 3) return 0;
    else return x * (x - 1) * (x - 2);
}
int x[N], y[N], d[N];
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            bool flag = true;
            while (c)
            {
                if ((c % 10 != 4) && (c % 10 != 7))
                {
                    flag = false;
                    break;
                }
                c /= 10;
            }
            if (!flag)
            {
                int fx = father(a);
                int fy = father(b);
                if (fx != fy) fa[fx] = fy;
            }
            x[i] = a, y[i] = b, d[i] = flag;
        }
        for (int i = 1; i <= n; ++i) fa[i] = father(fa[i]);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) cnt[fa[i]]++;
        int res = A(n, 3);
        for (int i = 1; i <= n; ++i)
            res -= A(cnt[i], 3);
        printf("%d\n", res);
    }
    return 0;
}
