#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define LL unsigned long long
#define MAXN 80010
using namespace std;
LL num[MAXN], a[MAXN], b[MAXN], n;
LL get_ans()
{
    for (LL i = 1; i <= n; ++i) { a[i] = i; b[i] = i; }
    num[0] = num[n + 1] = INT_MAX;
    a[0] = b[n + 1] = -1;
    for (LL i = 1; i <= n; ++i)
        while (num[a[i] - 1] < num[i]) a[i] = a[a[i] - 1];
    for (LL i = n; i >= 1; --i)
        while (num[b[i] + 1] < num[i]) b[i] = b[b[i] + 1];
    LL now_res = 0;
    for (LL i = 1; i <= n; ++i) now_res += (b[i] - i);
    return now_res;
}
int main()
{
    LL x;
    scanf("%llu", &n);
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; ++i)
        scanf("%llu", &num[i]);
    cout << get_ans() << endl;
    return 0;
}
