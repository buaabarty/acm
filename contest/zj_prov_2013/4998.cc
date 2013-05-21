#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt(int x, int y, int z) {
    int s[3], ans = 0, t;
    bool f[500];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int lx = 0; lx <= 2; ++lx)
        for (int ly = 0; ly <= 2; ++ly)
            for (int lz = 0; lz <= 2; ++lz) {
                //cout << lx << " " << ly << " " << lz << endl;
                memset(s, 0, sizeof(s));
                s[lx] += x;
                s[ly] += y;
                s[lz] += z;
                if (s[0] < s[1]) t = s[1] - s[0];
                else t = s[0] - s[1];
                if (!f[t]) {
                    ++ans;
                    f[t] = 1;
                }
            }
    return ans;
}
int main() {
    int T, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &x, &y);
        int res = 0;
        for (int i = 1; i < x; ++i)
            res = max(res, cnt(x-i, i, y));
        for (int i = 1; i < y; ++i)
            res = max(res, cnt(x, y-i, i));
        printf("%d\n", res);
    }
    return 0;
}
