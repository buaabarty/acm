#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int g[509][509], x[509], y[509];

int main() {
    int T, n, m;
    scanf("%d", &T);
    memset(g, 0, sizeof(g));
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) scanf("%d", &x[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &y[i]);
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (g[x[i]][y[i]] != ca) {
                ++cnt;
                g[x[i]][y[i]] = g[y[i]][x[i]] = ca;
            }
        }
        printf("%.3f\n", (double)cnt/(double)n);
    }

    return 0;
}
