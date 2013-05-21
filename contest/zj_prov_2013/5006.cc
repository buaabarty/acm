#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int T, n, m;
    int num[500], s[500];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            s[i] = s[i-1] + num[i];
        }
        for (int i = n + 1; i <= 2*n; ++i) {
            num[i] = num[i-n];
            s[i] = s[i-1] + num[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, s[i+m-1]-s[i-1]);
        printf("%d\n", ans);
    }
    return 0;
}
