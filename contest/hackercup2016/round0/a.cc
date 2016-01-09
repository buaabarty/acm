#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, n, x[2000], y[2000], dist[2000];
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            }
            sort(dist, dist + n);
            int now_cnt = 1;
            for (int j = 1; j < n; ++j) {
                if (dist[j] != dist[j - 1]) {
                    ans += now_cnt * (now_cnt - 1) / 2;
                    now_cnt = 1;
                } else {
                    now_cnt++;
                }
            }
            ans += now_cnt * (now_cnt - 1) / 2;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
