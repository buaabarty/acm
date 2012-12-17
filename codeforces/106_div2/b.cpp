#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 128
using namespace std;
int n, a[N], b[N], c[N], p[N];
bool f[N];
int main()
{
    while (~scanf("%d", &n))
    {
        memset(f, 1, sizeof(f));
        for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &p[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if ((i != j) && (a[i] < a[j]) && (b[i] < b[j]) && (c[i] < c[j])) f[i] = false;
        int x = -1, y = INT_MAX;
        for (int i = 1; i <= n; ++i)
            if (f[i] && (p[i] < y))
            {
                y = p[i];
                x = i;
            }
        printf("%d\n", x);
    }
    return 0;
}
