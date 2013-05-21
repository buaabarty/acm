#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1000010
#define eps 1e-6
using namespace std;
int n, m, k, p;
int num[N];
int del[N];
int now, ans;
inline int getans(int x)
{
    int s = 0;
    int a = x;
    while (a >= 1)
    {
        s++;
        a /= k;
    }
    return s;
}
int main()
{
//    freopen("tower.in", "r", stdin);
//    freopen("tower.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &num[i]);
        num[i] = getans(num[i]);
    }
    now = 0;
    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > m) now -= del[i - m];
        if (num[i] <= now) continue;
        else
        {
            del[i] = num[i] - now;
            now += del[i];
            ans += del[i];
        }
    }
    printf("%d\n", ans * p);
    return 0;
}
