#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000000 + 3;
struct data {
    int h, k;
    const bool operator < (const data &a) const {
        return h < a.h;
    }
} d[N];
int n, c[N];
int ans[N];
int lowbit(int x) {
    return x & (-x);
}
int getsum(int k) {
    int s = 0;
    while (k) {
        s += c[k];
        k -= lowbit(k);
    }
    return s;
}
void insert(int k, int delta) {
    while (k <= n) {
        c[k] += delta;
        k += lowbit(k);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &d[i].h, &d[i].k);
        }
        sort(d + 1, d + n + 1);
        memset(c, 0, sizeof(c));
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; ++i) {
            insert(i, 1);
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            int x = min(n - i - d[i].k, d[i].k);
            if (x < 0) {
                flag = false;
                break;
            }
            int left = 0, right = n, mid;
            while (left < right) {
                if (left + 1 == right) {
                    if (getsum(right) <= x) {
                        left = right;
                        break;
                    }
                }
                mid = (left + right + 1) / 2;
                if (getsum(mid) <= x) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            if (left == n || getsum(left) > x) {
                flag = false;
                break;
            }
            ans[left + 1] = d[i].h;
            insert(left + 1, -1);
        }
        if (!flag) {
            printf("Case #%d: impossible\n", ca);
        } else {
            printf("Case #%d:", ca);
            for (int i = 1; i <= n; ++i) {
                printf(" %d", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
