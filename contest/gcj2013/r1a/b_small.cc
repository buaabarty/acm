#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL T, E, R, N;
LL v[100010];

LL gao(LL l, LL r, LL s, LL t) {
    if (l >= r) return 0;
    LL k = l;
    for (LL i = k + 1; i < r; ++i)
        if (v[i] > v[k]) k = i;
    LL bg = s + R*(k-l);
    LL ed = t - R*(r-k);
    if (bg > E) bg = E;
    if (ed < 0) ed = 0;
    return gao(l, k, s, bg) + gao(k+1, r, min(ed+R, E), t) + (bg-ed)*v[k];
}

int main() {
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    scanf("%lld", &T);
    for (LL ca = 1; ca <= T; ++ca) {
        scanf("%lld%lld%lld", &E, &R, &N);
        //if (R > E) R = E;
        for (LL i = 0; i < N; ++i) {
            scanf("%lld", &v[i]);
        }
        printf("Case #%lld: %lld\n", ca, gao(0, N, E, 0));
    }
    return 0;
}
