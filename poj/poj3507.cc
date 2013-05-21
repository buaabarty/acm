#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[10];

int main() {
    while (scanf("%d%d%d%d%d%d", &num[1], &num[2], &num[3], &num[4], &num[5], &num[6])) {
        int tot = 0;
        for (int i = 1; i <= 6; ++i) tot += num[i];
        if (!tot) break;
        sort(num + 1, num + 7);
        tot = 0;
        for (int i = 2; i < 6; ++i) tot += num[i];
        double ans = tot;
        ans /= 4.0;
        printf("%g\n", ans);
    }
    return 0;
}
