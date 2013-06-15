#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        if (k >= n * (n - 1) / 2) puts("no solution");
        else {
            for (int i = 1; i <= n; ++i)
                printf("0 %d\n", i);
        }
    }
    return 0;
}
