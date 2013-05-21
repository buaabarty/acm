#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL factor[1000009], d2[1000009];
vector<pair<LL, LL> > A;
LL n, MOD;
LL pow(LL a, LL b){
    LL c = 1;
    while (b) {
        if (b&1) c = c*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return c;
}
int main() {
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i) {
        LL x; scanf("%I64d", &x);
        A.push_back(make_pair(x, i));
    }
    for (LL i = 1; i <= n; ++i) {
        LL x; scanf("%I64d", &x);
        A.push_back(make_pair(x, i));
    }
    scanf("%I64d", &MOD);
    factor[0] = 1, d2[0] = 0;
    for (LL i = 1; i <= 2 * n; ++i) {
        LL t = i; d2[i] = d2[i-1];
        while (t%2== 0) ++d2[i], t/=2;
        factor[i] = factor[i-1]*t%MOD;
    }
    sort(A.begin(), A.end());
    LL res1 = 1, res2 = 0;
    for (LL i = 0; i < A.size(); ++i) {
        LL j = i + 1;
        while (j<2*n && A[j].first == A[i].first) ++j;
        res1 = res1 * factor[j-i] % MOD;
        res2 += d2[j-i]; i = j - 1;
    }
    A.resize(unique(A.begin(), A.end())-A.begin());
    res2 -= (2*n - A.size());
    printf("%I64d\n", res1*pow(2, res2) % MOD);
    return 0;
}
