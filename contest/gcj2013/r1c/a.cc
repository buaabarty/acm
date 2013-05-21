#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000 + 9;
LL T, n;
char str[N];
bool okay(char c) {
    return (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u');
}
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%lld", &T);
    for (LL ca = 1; ca <= T; ++ca) {
        scanf("%s%lld", str, &n);
        LL len = strlen(str);
        bool got = false;
        LL next = 0, now = 0, ans = 0;
        for (LL i = len - 1; i >= 0; --i) {
            if (okay(str[i])) ++now;
            else now = 0;
            if (now >= n) {
                got = true;
                next = i;
            }
            //cout << next << endl;
            if (got) ans += len - (next+n-1LL);
        }
        printf("Case #%lld: %lld\n", ca, ans);
    }
    return 0;
}
