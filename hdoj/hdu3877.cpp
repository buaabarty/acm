#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define N 10010
using namespace std;
struct data
{
    LL a, b, c, o;
    char p;
    data(){}
    bool operator < (const data &a) const
    {
        return (c > a.c) || ((c == a.c) && (p > a.p)) || ((c == a.c) && (p == a.p) && (o < a.o));
    }
}d[N];
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%I64d%I64d", &d[i].a, &d[i].b);
            if (d[i].a > d[i].b) d[i].p = '>';
            else if (d[i].a < d[i].b) d[i].p = '<';
            else d[i].p = '=';
            d[i].c = d[i].a + d[i].b;
            d[i].o = i;
        }
        sort(d + 1, d + n + 1);
        for (int i = 1; i <= n; ++i)
            printf("%I64d+%I64d=[%c%I64d]\n", d[i].a, d[i].b, d[i].p, d[i].c);
        printf("\n");
    }
    return 0;
}
