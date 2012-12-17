#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
bool okay(int x, int y, int z, int k) {
    int f[3] = {x, y, z};
    int now = -1;
    for (int i = 1; i <= k; ++i)
    {
        now = (now + 1) % 3;
        while (!f[now]) now = (now + 1) % 3;
        f[now]--;

    }
    return (now == 0);
}
int main() {
    int f[100][100];
    for (int n = 1; n <= 15; ++n) {
        for (int k = n; k >= 1; --k) {
            //printf("========%d    %d=======\n", n, k);
            //printf("N=%d,K=%d:", n, k);
            int cnt = 0;
            for (int a = 1; a <= n; ++a)
                for (int b = 0; b <= n - a; ++b)
                        if (okay(a, b, n-a-b, k))
                            ++cnt;
            printf("%4d", cnt - f[n][k-1]);
            f[n][k] = cnt;
        }
        puts("");
    }
    return 0;
}
