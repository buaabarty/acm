#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[100010], b[100010];
int n, num[100010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    num[0] = num[n+1] = 1000000001;
    a[0] = b[n+1] = -1;
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = i;
    for (int i = 1; i <= n; ++i)
        while (num[a[i] - 1] <= num[i]) a[i] = a[a[i] - 1];
    for (int i = n; i >= 1; --i)
        while (num[b[i] + 1] <= num[i]) b[i] = b[b[i] + 1];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]-1 >= 1) ans = max(ans, num[i]^num[a[i]-1]);
        if (b[i]+1 <= n) ans = max(ans, num[i]^num[b[i]+1]);
    }
    printf("%d\n", ans);
    return 0;
}
