#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000 + 9;
int loc[N];
LL c[N];
int sq[N];
int n, m;
int num[N];
struct data {
    int l, r, id;
    LL ans;
} d[N];

bool cmp1(const data &a, const data &b) {
    return a.r < b.r;
}

bool cmp2(const data &a, const data &b) {
    return a.id < b.id;
}

bool cmp3(const data &a, const data &b) {
    return a.l > b.l;
}

int lowbit(int x) {
    return x&(-x);
}

void insert(int k, int delta) {
    while (k <= n) {
        c[k] += delta;
        k += lowbit(k);
    }
}

LL getsum(int k) {
    LL s = 0;
    while (k) {
        s += c[k];
        k -= lowbit(k);
    }
    return s;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        memset(loc, 0, sizeof(loc));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            sq[i] = (int)(sqrt(num[i])+1e-6);
            loc[num[i]] = i;
        }
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &d[i].l, &d[i].r), d[i].id = i;
        sort(d + 1, d + m + 1, cmp1);
        int now = 0;
        for (int i = 1; i <= m; ++i) {
            while (now < d[i].r) {
                ++now;
                int lim = sq[now];
                for (int i = 1; i <= lim; ++i)
                    if (!(num[now]%i)) {
                        if (loc[i] && loc[i] < now) insert(loc[i], 1);
                        int k = num[now]/i;
                        if (k!=i && loc[k] && loc[k] < now) insert(loc[k], 1);
                    }
            }
            d[i].ans = getsum(d[i].r) - getsum(d[i].l-1);
        }
        sort(d + 1, d + m + 1, cmp3);
        now = n + 1;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= m; ++i) {
            while (now > d[i].l) {
                --now;
                int lim = sq[now];
                for (int i = 1; i <= lim; ++i)
                    if (!(num[now]%i)) {
                        if (loc[i] && loc[i] > now) insert(loc[i], 1);
                        int k = num[now]/i;
                        if (k!=i && loc[k] && loc[k] > now) insert(loc[k], 1);
                    }
            }
            d[i].ans += getsum(d[i].r) - getsum(d[i].l - 1);
        }
        sort(d + 1, d + m + 1, cmp2);
        for (int i = 1; i <= m; ++i)
            printf("%I64d\n", d[i].ans+(d[i].r-d[i].l+1));
    }
    return 0;
}
