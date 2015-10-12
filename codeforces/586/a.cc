#include <iostream>
#include <cstdio>
using namespace std;
int n, d[101];
int main() {
    while (scanf("%d", &n) == 1) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (d[i-1] == 1 && d[i] == 0 && d[i+1] == 1) {
                d[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            sum += d[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
