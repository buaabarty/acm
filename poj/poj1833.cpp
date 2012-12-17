#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1024
using namespace std;
int main()
{
    int t, n, x, k;
    int num[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
        while (k--) next_permutation(num, num + n);
        for (int i = 0; i < n; ++i)
            printf("%d ", num[i]);
        printf("\n");
    }
    return 0;
}
