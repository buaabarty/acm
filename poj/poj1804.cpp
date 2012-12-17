#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1024
using namespace std;
int t, n, num[MAXN], res;
int main()
{
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        res = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (num[i] > num[j]) res++;
        printf("Scenario #%d:\n", ca);
        printf("%d\n", res);
        if (ca != t) printf("\n");
    }
    return 0;
}
