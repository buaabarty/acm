#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[200010], b[200010], n, x;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        b[x] = i;
    }
    for (int i = 1; i <= n; ++i) a[i] = b[a[i]];
    int res = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1])
        {
            res = n - i;
            break;
        }
    printf("%d\n", res);

    return 0;
}
