#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, v[4000], d[4000], p[4000];
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &v[i], &d[i], &p[i]);
        }
        int len = 0, res[4000], i = 0;
        while (i < n) {
            if (p[i] >= 0) {
                res[len++] = i;
                for (int j = i + 1; j < n && v[i] - (j - i) >= 0; ++j) {
                    p[j] -= (v[i] - (j - i));
                }
            } else {
                for (int j = i + 1; j < n; ++j) p[j] -= d[i];
            }
            ++i;
        }
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            printf("%d%c", res[i] + 1, " \n"[i == len - 1]);
        }
    }
    return 0;
}
