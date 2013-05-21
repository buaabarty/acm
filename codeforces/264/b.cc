#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

LL mm[100010], n, ans = 1, f[100010];
bool ip[100010];
LL prime[100010], pcnt = 0;

void pre() {
    memset(ip, 1, sizeof(ip));
    for (LL i = 2; i <= 100000; ++i)
        if (ip[i]) {
            for (LL j = i * 2; j <= 100000; j += i)
                ip[j] = 0;
            prime[++pcnt] = i;
        }
}

vector<LL> getps(LL x) {
    vector<LL> res;
    for (LL i = 1; prime[i]*prime[i]<=x; ++i)
        if (x%prime[i]==0) {
            res.push_back(prime[i]);
            while (x%prime[i]==0) x /= prime[i];
        }
    if (x > 1) res.push_back(x);
    return res;
}

int main() {
    pre();
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i) {
        LL x; scanf("%I64d", &x);
        vector<LL> ps = getps(x);
        for (LL j = 0; j < ps.size(); ++j)
            f[i] = max(f[i], mm[ps[j]]+1);
        for (LL j = 0; j < ps.size(); ++j)
            mm[ps[j]] = max(mm[ps[j]], f[i]);
        ans = max(ans, f[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
