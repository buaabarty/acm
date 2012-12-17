#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX_N 150
using namespace std;
bool use[MAX_N];
int inc(int x, int y)
{
    x++;
    if (x > y) x -= y;
    return x;
}
bool okay(int n, int m)
{
    memset(use, false, sizeof(use));
    use[1] = true;
    printf("1 ");
    for (int i = 1, j = 1; i < n - 1; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            j = inc(j, n);
            while (use[j])
            {
                j = inc(j, n);
            }
        }
        use[j] = true;
        printf("%d ", j);
    }
    for (int i = 1; i <= n; ++i)
        if (!use[i]) return i == 2;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        for (int i = 1; i < n; ++i)
            if (okay(n, i))
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
