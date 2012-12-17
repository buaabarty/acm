#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1000000
using namespace std;
int c[MAXN];
int n, m, a, x, y, dat[MAXN], nd;
int lowbit(int x)
{
    return x & (x ^ (x - 1));
}
int getsum(int x)
{
    int s = 0;
    for (; x > 0; s += c[x], x -= lowbit(x));
    return s;
}
void insert(int x)
{
    for (; x <= nd; c[x]++, x += lowbit(x));
}
int main()
{

    while(scanf("%d%d", &n, &m))
    {
        memset(c, 0, sizeof(c));
        nd = 0;
        if (n + m == 0) break;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &a);
                if (a == 0){
                    x = i, y = j;
                }
                else dat[++nd] = a;
            }
        int s = 0;
        for (int i = nd; i >= 1; --i)
        {
            if (dat[i] == 0) continue;
            s += getsum(dat[i] - 1);
            insert(dat[i]);
        }
        if (m % 2)
        {
            if (s % 2) printf("NO\n");
            else printf("YES\n");
        }
        else{
            if ((s % 2) ^ ((n - x) % 2)) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
