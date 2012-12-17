#include <iostream>
#include <cstdio>
#include <cstring>
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;
bool same(int a[110], int b[110], int n) {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) return false;
    return true;
}
void change1(int a[110], int b[110], int n) {
    int temp[110];
    for (int i = 1; i <= n; ++i)
        temp[i] = a[b[i]];
    for (int i = 1; i <= n; ++i)
        a[i] = temp[i];
}
void change2(int a[110], int b[110], int n) {
    int temp[110];
    for (int i = 1; i <= n; ++i)
        temp[b[i]] = a[i];
    for (int i = 1; i <= n; ++i)
        a[i] = temp[i];
}
int gcd(int x, int y) {
    if (x > y) swap(x, y);
    return (x) ? gcd(y % x, x) : y;
}
int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}
int calloop(int a[110], int n) {
    bool vst[110];
    clr(vst);
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        if (!vst[i]) {
            int x = i, cnt = 0;
            do {
                vst[x] = 1;
                x = a[x];
                ++cnt;
            } while (x != i);
            ans = lcm(ans, cnt);
        }
    return ans;
}
bool isodd(int x) {
    return !(x&1);
}
int main() {
    int n, k;
    int q[110], s[110], now[110], qq[110];
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &q[i]);
        qq[q[i]] = i;
        now[i] = i;
    }
    int loop = calloop(q, n);
    if (calloop(qq, n) != calloop(q, n)) while (1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]);
    bool flag = false;
    if (same(now, s, n)) {
        puts("NO");
        return 0;
    }
    int x = -1, y = -1;
    for (int i = 0; i <= k; ++i) {
        if (same(now, s, n)) {
            x = i; break;
        }
        change1(now, q, n);
    }
    for (int i = 1; i <= n; ++i) now[i] = i;
    for (int i = 0; i <= k; ++i) {
        if (same(now, s, n)) {
            y = i; break;
        }
        change2(now, q, n);
    }
    if (x == -1 && y == -1 || x == 0) puts("NO");
    else if (x == 1 && y == 1) {
        if (k == 1) puts("YES");
        else puts("NO");
    } else if (x != -1 && isodd(k-x) || y != -1 && isodd(k-y)) puts("YES");
    else puts("NO");
    return 0;
}
