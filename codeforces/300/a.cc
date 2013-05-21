#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100 + 9;
int n, num[N], a, b, c;
bool use[N];
int main() {
    while (scanf("%d", &n) == 1) {
        a = b = c = 0;
        memset(use, 0, sizeof(use));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            if (num[i] > 0) ++a;
            else if (num[i] == 0) ++b;
            else ++c;
        }
        if (c&1) {
            int cnt1 = c;
            if (!a) cnt1 -= 2;
            printf("%d", cnt1);
            for (int i = 1, now = 0; i <= n; ++i)
                if (num[i] < 0) {
                    ++now;
                    if (now > cnt1) break;
                    printf(" %d", num[i]);
                    use[i] = 1;
                }
            printf("\n");
            printf("%d", a+(c-cnt1));
            for (int i = 1; i <= n; ++i)
                if (num[i] > 0) printf(" %d", num[i]);
            for (int i = 1, now = 0; i <= n; ++i)
                if (!use[i] && num[i] < 0) {
                    ++now;
                    if (now > (c-cnt1)) break;
                    printf(" %d", num[i]);
                    use[i] = 1;
                }
            printf("\n");
            printf("%d", b);
            for (int i = 1; i <= n; ++i)
                if (num[i] == 0) printf(" %d", num[i]);
            printf("\n");
        } else {
            int cnt1 = c-1;
            if (!a) cnt1 -= 2;
            printf("%d", cnt1);
            for (int i = 1, now = 0; i <= n; ++i)
                if (num[i] < 0) {
                    ++now;
                    if (now > cnt1) break;
                    printf(" %d", num[i]);
                    use[i] = 1;
                }
            printf("\n");
            printf("%d", a+(c-cnt1)-1);
            for (int i = 1; i <= n; ++i)
                if (num[i] > 0) printf(" %d", num[i]);
            for (int i = 1, now = 0; i <= n; ++i)
                if (!use[i] && num[i] < 0) {
                    ++now;
                    if (now > (c-cnt1-1)) break;
                    printf(" %d", num[i]);
                    use[i] = 1;
                }
            printf("\n");
            printf("%d", b+1);
            for (int i = 1; i <= n; ++i)
                if (num[i] == 0) printf(" %d", num[i]);
            for (int i = 1; i <= n; ++i)
                if (!use[i] && num[i] < 0) {
                    printf(" %d", num[i]);
                    break;
                }
            printf("\n");
        }

    }
    return 0;
}
