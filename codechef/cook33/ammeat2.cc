#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k * 2 > n) puts("-1");
        else {
            for (int i = 1; i <= k; ++i)
                printf("%d%c", i*2, " \n"[i==k]);
        }
    }
    return 0;
}
