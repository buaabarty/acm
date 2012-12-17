#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200001;
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
int cnt[maxn*4], num[maxn], res[maxn];
void build(int p, int l, int r) {
    if (l == r) {
        cnt[p] = 1;
        return;
    }
    if (l <= mid) build(pl, l, mid);
    if (mid+1 <= r) build(pr, mid+1, r);
    cnt[p] = cnt[pl] + cnt[pr];
}
void insert(int p, int l, int r, int d, int x) {
    cnt[p]--;
    if (l == r) {
        res[l] = x;
        return ;
    }
    if (d + 1 <= cnt[pl]) insert(pl, l, mid, d, x);
    else insert(pr, mid + 1, r, d - cnt[pl], x);
}
bool read(int &x) {
    char c = getchar();
    x = 0;
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
}
int dat[maxn], n;
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++i) {
            read(dat[i]); read(num[i]);
        }
        build(1, 1, n);
        for (int i = n; i >= 1; --i) {
            insert(1, 1, n, dat[i], num[i]);
        }
        for (int i = 1; i <= n; ++i)
            printf("%d%c", res[i], " \n"[i==n]);
    }
    return 0;
}
