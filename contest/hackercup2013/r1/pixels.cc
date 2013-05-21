#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct point {
    int x, y;
}d[100010];
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int w, h, p, q, n, a, b, c, d;
        scanf("%d%d%d%d%d%d%d%d%d%d%d", &w, &h, &p, &q, &n, &d[0].x, &d[0].y, &a, &b, &c, &d);
        for (int i = 1; i <= n; ++i) {
            d[i].x = (d[i-1].x * a + d[i-1].y * b + 1) % w;
            d[i].y = (d[i-1].x * c + d[i-1].y * d + 1) % h;
        }
    }
    return 0;
}
