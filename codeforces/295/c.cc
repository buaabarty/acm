#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
LL n, k;
LL d[51], A, B;
LL f[55][55][300];
LL c[55][55];
int main() {
    scanf("%I64d%I64d", &n, &k);
    A = 0, B = 0;
    for (LL i = 1; i <= n; ++i) {
        scanf("%I64d", &d[i]);
        if (d[i] == 50) ++A;
        else ++B;
    }
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (LL i = 2; i <= 50; ++i) {
        c[i][0] = 1;
        for (LL j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
    f[A][B][0] = 1;
    for (LL t = 0; t < 250; ++t)
        for (LL x = 0; x <= A; ++x)
            for (LL y = 0; y <= B; ++y) {
                LL rx = x, ry = y;
                if (t&1) { rx = A - x; ry = B - y; }
                for (LL dx = 0; dx <= rx; ++dx)
                    for (LL dy = 0; dy <= ry; ++dy) if (dx+dy) {
                        if (dx*50+dy*100>k) continue;
                        LL nx = x-dx, ny = y-dy;
                        if (t&1) nx = x+dx, ny = y+dy;
                        if (nx > A || ny > B || nx < 0 || ny < 0) continue;
                        f[nx][ny][t+1] = (f[nx][ny][t+1] + (((f[x][y][t]*c[rx][dx])%mod)*c[ry][dy])%mod)%mod;
                    }
            }
    bool find = false;
    for (LL t = 0; t < 250; ++t)
        if (f[0][0][t]) {
            find = true;
            printf("%I64d\n%I64d\n", t, f[0][0][t]);
            break;
        }
    if (!find) puts("-1\n0");
    return 0;
}
