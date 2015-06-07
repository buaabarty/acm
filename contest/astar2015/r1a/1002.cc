#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int n, m;
int mmin[10000 + 9][15];
int mmax[10000 + 9][15];
struct d {
    int x, i;
    bool operator < (const d& a) const {
        return x < a.x;
    }
} d[10000 + 9];
int a[10000 + 9];
int cnt[10000 + 9];
int getmin(int l, int r) {
    int len = (int)(log2(r - l + 1) + 1e-6);
    return min(mmin[l][len], mmin[r-(1<<len)+1][len]);
}
int getmax(int l, int r) {
    int len = (int)(log2(r - l + 1) + 1e-6);
    return max(mmax[l][len], mmax[r-(1<<len)+1][len]);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &d[i].x);
        d[i].i = i;
    }
    sort(d, d + n);
    a[d[0].i] = 0;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (d[i].x != d[i - 1].x) ++j;
        a[d[i].i] = j;
    }
    for (int i = 0; i < n; ++i) {
        mmin[i][0] = a[i];
        mmax[i][0] = a[i];
    }
    for (int i = 1; i < 15; ++i)
        for (int j = 0; j + (1<<i) - 1 < n; ++j) {
            mmin[j][i] = min(mmin[j][i - 1], mmin[j + (1<<(i-1))][i-1]);
            mmax[j][i] = max(mmax[j][i - 1], mmax[j + (1<<(i-1))][i-1]);
        }
    printf("Case #1:\n");
    while (m--) {
        memset(cnt, 0, sizeof(cnt));
        int x, s = 0, res = 0;
        scanf("%d", &x);
        for (int i = 0; i < x; ++i) {
            if (!cnt[a[i]]) {
                ++s;
            }
            cnt[a[i]]++;
        }
        if (s == x && getmax(0, x - 1) - getmin(0, x - 1) == x - 1) ++res;
        for (int i = x; i < n; ++i) {
            if (cnt[a[i - x]] == 1) {
                --s;
            }
            --cnt[a[i - x]];
            if (!cnt[a[i]]) {
                ++s;
            }
            ++cnt[a[i]];
            if (s == x && getmax(i - x + 1, i) - getmin(i - x + 1, i) == x - 1) ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
