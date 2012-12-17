#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 20000
using namespace std;
long long n;
long long s = 0, num[MAXN];
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &num[i]);
    sort(num + 1, num + n + 1);
    for (long long i = 1, t = 2 - n * 2; i <= n; ++i, t += 4)
        s = s + num[i] * t;
    printf("%lld\n", s);
    return 0;
}
