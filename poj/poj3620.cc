#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mat[110][110], n, m, k;
int vst[110][110];
int now;
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
void dfs(int x, int y) {
    vst[x][y] = 1;
    ++now;
    for (int i = 0; i < 4; ++i) {
        int dx = x + d[i][0], dy = y + d[i][1];
        if (dx<=0||dx>n||dy<=0||dy>m) continue;
        if (mat[dx][dy] && !vst[dx][dy]) dfs(dx, dy);
    }
}
int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(mat, 0, sizeof(mat));
        memset(vst, 0, sizeof(vst));
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            mat[x][y] = 1;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (mat[i][j] && !vst[i][j]) {
                    now = 0;
                    dfs(i, j);
                    if (now > res) res = now;
                }
        printf("%d\n", res);
    }
    return 0;
}
