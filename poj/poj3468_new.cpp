#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
#define maxn 1000010
#define LL long long
using namespace std;
LL n, q;
LL sum[maxn*4], a[maxn], delay[maxn*4];
void build(LL p, LL l, LL r) {
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    build(pl, l, mid);
    build(pr, mid + 1, r);
    sum[p] = sum[pl] + sum[pr];
}
LL getsum(LL p, LL l, LL r, LL a, LL b) {
    if (delay[p]) {
        delay[pl] += delay[p];
        delay[pr] += delay[p];
        sum[pl] += delay[p] * (mid - l + 1);
        sum[pr] += delay[p] * (r - mid);
        delay[p] = 0;
    }
    if (l == a && r == b) return sum[p];
    if (b <= mid) return getsum(pl, l, mid, a, b);
    if (a >  mid) return getsum(pr, mid + 1, r, a, b);
    return getsum(pl, l, mid, a, mid) + getsum(pr, mid + 1, r, mid + 1, b);
}
void insert(LL p, LL l, LL r, LL a, LL b, LL delta) {
    ///prLLf("%lld %lld %lld %lld %lld %lld\n", p, l, r, a, b, delta);
    //system("pause");
    sum[p] += (delta) * (b - a + 1);
    if (l == a && r == b) {
        delay[p] += delta;
        return;
    }
    if (b <= mid) insert(pl, l, mid, a, b, delta);
    else if (a >  mid) insert(pr, mid + 1, r, a, b, delta);
    else {
        insert(pl, l, mid, a, mid, delta);
        insert(pr, mid + 1, r, mid + 1, b, delta);
    }
}
char str[3];
void read(LL &x) {
    char c = getchar(); x = 0;
    LL f = 1;
    while (!isdigit(c) && (c != '-')) c = getchar();
    if (c == '-') {
        f = -1;
        c = getchar();
    }
    else if (c == '+') {
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10LL + (long long)(c - '0');
        c = getchar();
    }
    x = x * f;
}
LL x, y, d;
int main() {
    while (~scanf("%lld%lld", &n, &q)) {
        memset(sum, 0, sizeof(sum));
        memset(delay, 0, sizeof(delay));
        for (LL i = 1; i <= n; ++i) {
            read(a[i]);
        }
        build(1, 1, n);
        while (q--) {
            scanf("%s", str);
            read(x); read(y);
            if (str[0] == 'Q') {
                printf("%lld\n", getsum(1, 1, n, x, y));
            }
            else {
                read(d);
                insert(1, 1, n, x, y, d);
            }
        }
    }
    return 0;
}
