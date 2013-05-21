#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n, a[50010];
struct data {
    int d, l, r;
    data(int _d) {
        l = -1, r = -1;
        d = _d;
    }
    data() {}
} d[50010];
int dcnt;
int s1, s2;

void insert(int p, int x) {
    if (x < d[p].d) {
        if (d[p].l == -1) {
            ++s1;
            d[p].l = ++dcnt;
            d[dcnt] = data(x);
        } else {
            ++s1;
            insert(d[p].l, x);
        }
    } else {
        if (d[p].r == -1) {
            ++s1, ++s2;
            d[p].r = ++dcnt;
            d[dcnt] = data(x);
        } else {
            ++s1; ++s2;
            insert(d[p].r, x);
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        dcnt = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        d[++dcnt] = data(a[1]);
        s1 = 4, s2 = 2;
        for (int i = 2; i <= n; ++i) {
            s1 += 2, s2 += 1;
            insert(1, a[i]);
        }
        printf("Case #%d: %d %d\n", ca, s1, s2);
    }
    return 0;
}
