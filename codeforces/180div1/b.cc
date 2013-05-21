#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;

int a[100010], b[100010];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    bool flag = true;
    int l = 1;
    for (int i = 1; i <= n; ++i) {
        while (l < m && a[i] > b[l]) ++l;
        if (a[i] > b[l]) {
            flag = false;
            break;
        }
        ++l;
    }
    if (flag) puts("NO");
    else puts("YES");
    return 0;
}
