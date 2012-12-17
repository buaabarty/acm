#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1000000001
using namespace std;
void update(int &x, int y) {
    if (y < x) x = y;
}
int l1, l2, l3, c1, c2, c3, p1, p2, p3, n, x[10010];
int f[10010], st, ed;
int main() {
    while (~scanf("%d%d%d%d%d%d", &l1, &l2, &l3, &c1, &c2, &c3)) {
        scanf("%d", &n);
        scanf("%d%d", &st, &ed);
        if (st > ed) swap(st, ed);
        for (int i = 1; i <= n; ++i) f[i] = INF;
        f[st] = 0;
        memset(x, 0, sizeof(x));
        for (int i = 2; i <= n; ++i) scanf("%d", &x[i]);
        p1 = st; p2 = st; p3 = st;
        for (int i = st + 1; i <= ed; ++i) {
            while (x[i] - x[p1] > l1) p1++;
            while (x[i] - x[p2] > l2) p2++;
            while (x[i] - x[p3] > l3) p3++;
            update(f[i], min(min(f[p1] + c1, f[p2] + c2), f[p3] + c3));
        }
        printf("%d\n", f[ed]);
    }
    return 0;
}
