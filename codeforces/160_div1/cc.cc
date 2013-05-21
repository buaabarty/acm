#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL f[50][50];

LL get(LL x, LL y) {
    if (y == -1) return 1LL;
    else return f[x][y];
}

LL gao(LL mm, LL mt, LL x, LL t) {
    if (mt == 0) return (t == -1);
    if (t < -1) return 0;
    if (x < mm/2LL) return gao(mm/2LL, mt-1, x, t);
    else {
        return gao(mm/2LL, mt-1, x-mm/2LL, t-1) + get(mt-1, t);
    }
}

int main() {
    f[1][0] = 1;
    for (LL i = 2; i < 50; ++i) {
        for (LL j = 0; j <= i; ++j) {
            f[i][j] = f[i-1][j];
            if (j) f[i][j] += f[i-1][j-1];
        }
        f[i][0]++;
    }
    LL n, t;
    scanf("%I64d%I64d", &n, &t);
    ++n;
    if ((t&-t) != t) {
        printf("0\n");
        return 0;
    }
    LL ss = 1, st = 0;
    while (ss <= n) {
        ss = ss * 2LL;
        ++st;
    }
    LL rt = 0;
    while (t > 1) {
        rt++; t >>= 1LL;
    }
    LL ans = gao(ss, st, n, rt);
    if (rt == 0) ans--;
    printf("%I64d\n", ans);
    return 0;
}
