#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, fa[100010], l[100010], res = 0;
int father(int v)
{
    int s = 0, sv = v;
    while (fa[v] != v)
    {
        printf("%d\n", v);
        s += l[v];
        v = fa[v];
    }
    fa[sv] = v;
    l[sv] = s;
    printf("%d %d\n", sv, fa[sv]);
    return fa[sv];
}
int main()
{
    freopen("input.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        l[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", i);
        int k, v, x;
        scanf("%d", &k);
        while (k--)
        {
            scanf("%d%d", &v, &x);
            int fx = father(x);
            int lx = l[x];
            fa[fx] = i;
            l[fx] = v + lx;
        }
        for (int j = 1; j <= n; ++j)
            printf("%d\t", fa[j]);
        puts("");
    }
    return 0;
}
