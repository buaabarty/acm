#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int n, s[MAXN], a, b;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int len = 0;
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &a, &b);
            if (a > b) swap(a, b);
            a = (a - 1) >> 1;
            b = (b - 1) >> 1;
            len = max(len, b);
            for (int j = a; j <= b; ++j)
                s[j]++;
        }
        int res = 0;
        for (int i = 0; i <= len; ++i)
            res = max(res, s[i]);
        printf("%d\n", res * 10);
    }
    return 0;
}
