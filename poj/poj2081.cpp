#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 3012510
using namespace std;
int a[MAXN], x;
bool app[MAXN];
bool legal(int n)
{
    return (n > 0) && !app[n];
}
int main()
{
    memset(app, false, sizeof(app));
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= 500000; ++i)
    {
        a[i] = a[i - 1] - i;
        if (!legal(a[i])) a[i] = a[i - 1] + i;
        app[a[i]] = true;
    }
    while (scanf("%d", &x))
    {
        if (x < 0) break;
        printf("%d\n", a[x]);
    }
    return 0;
}
