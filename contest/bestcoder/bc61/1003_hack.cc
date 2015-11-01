#include <iostream>
using namespace std;
int gao(int x, int n) {
    int s = 1;
    if (x * 2 <= n) s += gao(x * 2, n);
    if (x * 2 + 1 <= n) s += gao(x * 2 + 1, n);
    return s;
}
int main() {
    for (int i = 1; i <= 1000; ++i) {
        int a[2000];
        memset(a, 0, sizeof(a));
        for (int j = 1; j <= i; ++j) a[gao(j, i)] = 1;
        int cnt = 0;
        for (int j = 1; j <= i; ++j) cnt += a[j];
        printf("%d\n", cnt);
    }
    return 0;
}
