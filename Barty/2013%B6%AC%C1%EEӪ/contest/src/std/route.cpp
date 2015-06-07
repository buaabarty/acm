#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const LL inf = 10000000000000LL;
const int N = 110;

class func {
    template <typename T> T checkmax(T &a, const T &b) { if (b > a) a = b; }
    LL gcd(LL x, LL y) {
        return (x) ? gcd(y % x, x) : y;
    }
    LL n, s, t, g[N][N], f[N][N];
    public: void gao() {
        scanf("%lld%lld%lld", &n, &s, &t);
        for (LL i = 1; i < n; ++i) {
            for (LL j = i + 1; j <= n; ++j) {
                scanf("%lld", &g[i][j]);
                g[j][i] = g[i][j];
            }
        }
        memset(f, 0, sizeof(f));
        f[s][0] = inf;
        for (LL l = 1; l <= n; ++l) {
            for (LL i = 1; i <= n; ++i)
                for (LL j = 1; j <= n; ++j)
                    if (i != j) {
                        LL tmp = min(f[j][l-1], g[j][i]);
                        checkmax(f[i][l], tmp);
                    }
        }
        LL x = 0, y = 1;
        for (LL i = 1; i <= n; ++i)
            if (x * i < f[t][i] * y) {
                x = f[t][i];
                y = i;
            }
        LL g = gcd(x, y);
        x /= g;
        y /= g;
        if (y > 1LL) printf("%I64d/%I64d\n", x, y);
        else printf("%I64d\n", x);
    }
};
int main() {
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    func a;
    a.gao();
    return 0;
}
