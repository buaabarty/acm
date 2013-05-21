#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int num[300];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n-1; ++i) scanf("%d", &num[i]);
    sort(num + 1, num + 2*n-1 + 1);
    if (n&1) {
        int ans = 0;
        for (int i = 1; i <= n*2-1; ++i)
            if (num[i] < 0) ans += -num[i];
            else ans += num[i];
        printf("%d\n", ans);
    } else {
        for (int i = 1; i < n; ++i)
            if (num[i*2-1]+num[i*2]<0) {
                num[i*2-1] = -num[i*2-1];
                num[i*2] = -num[i*2];
            }
        int ans = 0;
        for (int i = 1; i <= 2*n-1; ++i)
            ans += num[i];
        printf("%d\n", ans);
    }
    return 0;
}
