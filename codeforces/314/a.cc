#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;


LL n, k;
LL tot;
LL num[1000000 + 9];

int main() {
    while (scanf("%I64d%I64d", &n, &k) == 2) {
        tot = 0;
        LL nown = n, nows = 0;
        for (LL i = 1; i <= n; ++i) scanf("%I64d", &num[i]);
        bool first = true;
        for (LL i = 1; i <= n; ++i) {
            LL x = num[i];
            LL ans = tot - x * (nown - (nows+1LL)) * nows;
            if (ans < k) {
                --nown;
                printf("%I64d\n", i);
            } else {
                ++nows;
                tot += x * (nows - 1);
            }
        }
    }
    return 0;
}
