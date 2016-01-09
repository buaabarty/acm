#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m, p[200000], cnt[200000], size = 0;
int pow(int x, int y) {
    int ret = 1, pw = x;
    while (y) {
        if (y&1) {
            ret = ret * pw;
        }
        y >>= 1;
        pw *= pw;
    }
    return ret;
}
int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &p[i]);
    }
    sort(p, p + m);
    cnt[0] = 1;
    size = 1;
    for (int i = 1; i < m; ++i) {
        if (p[i] != p[size - 1]) {
            p[size] = p[i];
            cnt[size++] = 1;
        } else {
            cnt[size - 1]++;
        }
    }
    int ans = 1;
    for (int i = 0; i < size; ++i) {
        ans = (ans * pow(p[i], cnt[i] * (cnt[i] - 1) / 2));
    }
    cout << ans << endl;
    return 0;
}
