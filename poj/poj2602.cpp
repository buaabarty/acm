#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 1000010
using namespace std;
int a[MAXN], x, n;
bool init()
{
    if (scanf("%d", &n) == EOF) return false;
    memset(a, 0, sizeof(a));
    getchar();
    for (int i = n; i >= 1; --i)
    {
        a[i] = getchar() - '0';
        getchar();
        x = getchar() - '0';
        a[i] += x;
        getchar();
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    return true;
}
int main()
{
    init();
    for (int i = n; i >= 1; --i)
        putchar(a[i] + '0');
    putchar('\n');
    return 0;
}
