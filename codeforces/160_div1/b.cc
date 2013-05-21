#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double f[51][51][51];
int n, a[51], p;
double P[51];

int main() {
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    scanf("%d", &p);
    if (s <= p) {
        printf("%d.00000\n", n);
        return 0;
    }
    P[0] = 1;
    for (int i = 1; i <= n; ++i) P[i] = P[i-1] * (double)i;
    for (int i = 1; i <= n; ++i)
        if (a[i] > p) a[i] = p + 1;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) f[0][0][i] = 1;
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x) if (y != x)
            for (int j = n; j >= 1; --j)
                for (int i = p; i >= 1; --i)
                    if (i >= a[y]) f[i][j][x] += f[i-a[y]][j-1][x];
    double tot = 0;
    for (int i = 1; i <= n; ++i)
        for (int ls = p - a[i] + 1; ls <= p; ++ls)
            for (int lt = 0; lt <= n; ++lt)
                tot += f[ls][lt][i] * lt * P[n-lt-1] * P[lt];
    tot /= P[n];
    printf("%.8f\n", tot);
    return 0;
}
