#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n, a[20];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        int cnt = n, j = n;
        while (j) {
            if (a[j--] == cnt) {
                --cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
