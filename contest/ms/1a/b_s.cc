#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1009], b[1009];
int n, m;
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%s%s", a, b);
        n = strlen(a), m = strlen(b);
        int ans = n + m;
        for (int i = 0; i <= n - m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j)
                if (a[i+j] != b[j]) ++s;
            ans = min(ans, s);
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
