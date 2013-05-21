#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, R, N, M, K;
int s[10], d[10];
int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &T, &R, &N, &M, &K);
    printf("Case #1:\n");
    for (int i = 1; i <= R; ++i) {
        for (int j = 0; j < K; ++j) scanf("%d", &s[j]);
        bool find = false;
        for (int x = 2; x <= M; ++x) if (!find)
            for (int y = 2; y <= M; ++y) if (!find)
                for (int z = 2; z <= M; ++z) if (!find) {
                    int cnt = 0;
                    for (int sy = 0; sy <= 1; ++sy)
                        for (int sx = 0; sx <= 1; ++sx)
                            for (int sz = 0; sz <= 1; ++sz) {
                                int pro = 1;
                                if (sx) pro *= x;
                                if (sy) pro *= y;
                                if (sz) pro *= z;
                                d[cnt++] = pro;
                            }
                    sort(d, d+8);
                    bool can = true;
                    for (int j = 0; j < K; ++j) {
                        bool f = false;
                        for (int k = 0; k < 8; ++k)
                            if (d[k] == s[j]) {
                                f = true;
                                break;
                            }
                        if (!f) {
                            can = false;
                            break;
                        }
                    }
                    if (can) {
                        find = true;
                        printf("%d%d%d\n", x, y, z);
                        break;
                    }
                }
        if (!find) printf("222\n");
    }
    return 0;
}
