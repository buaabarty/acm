#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
using namespace std;
int fa[N], n, num[N];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
void ooxx(int x, int y)
{
    int fx = father(x);
    int fy = father(y);
    if (fx != fy) fa[fx] = fy;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) { scanf("%d", &num[i]); fa[i] = i; }
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            if (i - x > 0) ooxx(i - x, i);
            if (i + x <= n) ooxx(i, i + x);
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
            if (father(i) != father(num[i]))
            {
                flag = false;
                break;
            }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
