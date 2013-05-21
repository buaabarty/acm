#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

struct data {
    int s, loc;
    bool operator < (const data &a) const {
        return s < a.s;
    }
} d[100010];

int n;
int a[100010], b[100010];
set<int> sa, sb;
int ansa[100010], ansb[100010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i].s), d[i].loc = i;
    sort(d + 1, d + n + 1);
    int k = (n+2) / 3;
    for (int i = 1; i <= k; ++i) {
        b[i] = 0;
        a[i] = d[i].s;
    }
    for (int i = 1; i <= k && i <= n - k; ++i) {
        b[n-i+1] = i-1;
        a[n-i+1] = d[n-i+1].s - i + 1;
    }
    for (int i = k + 1; i <= n - k; ++i) {
        b[i] = i - 1;
        a[i] = d[i].s - i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        ansa[d[i].loc] = a[i];
        ansb[d[i].loc] = b[i];
    }
    puts("YES");
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ansa[i], " \n"[i==n]);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ansb[i], " \n"[i==n]);
    return 0;
}
