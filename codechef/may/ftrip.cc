#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

long double c[1100][1100];

int main() {
    int T, s, n, m, k;
    scanf("%d", &T);
    memset(c, 0,sizeof(c));
    c[0][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    while (T--) {
        scanf("%d%d%d%d", &s, &n, &m, &k);
        if (min(n, m)< max(k+1, n-s+m)) {
            printf("0.000000\n");
            continue;
        }
        long double ans = 0;
        for (int i = max(k + 1, n-s+m); i <= min(n, m); ++i)
            ans += c[s-m][n-i]*c[m-1][i-1];
        ans = ans / c[s-1][n-1];
        printf("%.10f\n", (double)ans);
    }
    return 0;
}
