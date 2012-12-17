#include <iostream>
#include <cstdio>
#define MAXN 32
using namespace std;
int main()
{
    int t, n, num[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        sort(num + 1, num + n + 1);
        int s = 0, x = (n + 1) / 2;
        for (int i = 1; i <= n; ++i)
            s += myabs(num[i] - num[x]);
        printf("%d\n", s);
    }
    return 0;
}
