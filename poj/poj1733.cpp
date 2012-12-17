#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int fa[MAXN], n, m, x, y, d, l[MAXN];
char str[10];
int father(int v)
{
    while (v != fa[v])
    {
        if ()
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    memset(l, 0, sizeof(l));
    bool flag = false;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%s", &x, &y, str);
        if (str[0] == 'e') d = 1;
        else d = 0;
        int fx = father(x), fy = father(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            l[fx] = d;
        }
        else
        {
            if (((l[x] - l[y] + 2) % 2) != d)
            {
                printf("%d\n", i);
                flag = true;
                break;
            }
        }
    }
    if (!flag) printf("%d\n", m + 1);
    return 0;
}
