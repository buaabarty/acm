#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n, dat[2][1000], size[2000];
char buff[1001];
bool use[2000];
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        memset(dat, 0, sizeof(dat));
        for (int i = 0; i < 2; ++i) {
            scanf("%s", buff);
            for (int j = 0; j < n; ++j) {
                if (buff[j] == 'X') {
                    dat[i][j] = -1;
                }
            }
        }
        int cnt = 0;
        memset(size, 0, sizeof(size));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dat[i][j] != -1) {
                    if (j && dat[i][j - 1] != -1) {
                        dat[i][j] = dat[i][j - 1];
                    } else {
                        dat[i][j] = cnt++;
                    }
                    size[dat[i][j]]++;
                }
            }
        }
        int ans = cnt;
        memset(use, 0, sizeof(use));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dat[i][j] != -1 && size[dat[i][j]] == 1) {
                    if (dat[1 - i][j] != -1 && !use[dat[1 - i][j]]) {
                        use[dat[1 - i][j]] = 1;
                        use[dat[i][j]] = 1;
                        --ans;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
