#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int ans[1000010];
int gao(int x) {
    int s = 0;
    while (x) {
        s = s * 2 + !(x & 1);
        x >>= 1;
    }
    return s;
}
int main() {
    scanf("%d", &n);
    for (int i = n; i >= 0; --i)
        if (!ans[i]) {
            int x = gao(i);
            ans[x] = i;
            ans[i] = x;
        }
    int tot = 0;
    for (int i = 0; i <= n; ++i)
        tot = tot + (i ^ ans[i]);
    printf("%d\n", tot);
    for (int i = 0; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
