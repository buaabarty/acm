#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n, m, INF;
    scanf("%d%d", &n, &m);
    INF = m * m;
    if (m == 3 && n > 4) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", i, i*i);
    for (int i = 1; i <= n - m; ++i)
        printf("%d %d\n", i, -INF-i*i);
    return 0;
}
