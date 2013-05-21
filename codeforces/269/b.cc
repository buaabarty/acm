#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;


int f[5010];
int n, m;
int d[5010];
double x[5010];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%lf", &d[i], &x[i]);
    memset(f, 0, sizeof(f));
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j)
            if (d[j] <= d[i]) f[i] = max(f[i], f[j] + 1);
        ans = min(ans, n - f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
