#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int fa[MAXN], l[MAXN];
int t, n, x, y;
char str[2];
int get_ans(int v)
{
    if (fa[v] != v)
    {
        int temp = get_ans(fa[v]);
        l[v] += l[fa[v]];
        fa[v] = fa[fa[v]];
        return l[v];
    }
    else return 0;
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) { fa[i] = i, l[i] = 0; }
        while (scanf("%s", str), (str[0] != 'O'))
        {
            if (str[0] == 'E')
            {
                scanf("%d", &x);
                printf("%d\n", get_ans(x));
            }
            else
            {
                scanf("%d%d", &x, &y);
                get_ans(x);
                get_ans(y);
                fa[x] = y;
                l[x] = iabs(x - y) % 1000;
            }
        }
    }
    return 0;
}
