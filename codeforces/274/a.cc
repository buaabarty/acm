#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
LL n, m;
LL a[100010];
bool vst[100010];
set<LL> loc;
int main() {
    scanf("%I64d%I64d", &n, &m);
    for (LL i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    if (m == 1) {
        printf("%I64d\n", n);
        return 0;
    }
    memset(vst, 0, sizeof(vst));
    sort(a + 1, a + n + 1);
    LL ans = 0;
    for (LL i = 1; i <= n; ++i)
        if (a[i] % m || loc.find(a[i]/m) == loc.end()) loc.insert(a[i]);
    printf("%I64d\n", (LL)loc.size());
    return 0;
}
