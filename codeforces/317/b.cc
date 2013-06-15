#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int K = 160;
int dat[2][K][K], n, t;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
    //while (scanf("%d%d", &n, &t) == 2) {
    scanf("%d%d", &n, &t);
        memset(dat, 0, sizeof(dat));
        int now = 0;
        dat[1][K/2][K/2] = n;
        bool find;
        do {
            find = false;
            for (int i = 1; i < K; ++i)
                for (int j = 1; j < K; ++j)
                    if (dat[1-now][i][j] >= 4) {
                        find = true;
                        for (int k = 0; k < 4; ++k) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            //if (!nx || !ny) puts("OMG");
                            dat[now][nx][ny] += dat[1-now][i][j] / 4;
                        }
                        dat[now][i][j] += dat[1-now][i][j] % 4;
                    } else dat[now][i][j] += dat[1-now][i][j];
            //int tot = 0;
            //for (int i = 1; i <= 99; ++i)
            //    for (int j = 1; j <= 99; ++j) {
            //        printf("%d%c", dat[now][i][j], " \n"[j==19]);
            //        tot += dat[now][i][j];
            //    }
            //cout << tot << endl;
            //system("pause");
            now = 1 - now;
            memset(dat[now], 0, sizeof(dat[now]));
        } while (find);
        for (int i = 1; i <= t; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x < -K/2 || y < -K/2 || x > K/2 || y > K/2) printf("0\n");
            else printf("%d\n", dat[1-now][x+K/2][y+K/2]);
        }
    //}
    return 0;
}
