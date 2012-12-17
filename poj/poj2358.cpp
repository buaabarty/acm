#include <iostream>
#include <cstdio>
#include <cstring>
#define CLR(x) memset(x, 0, sizeof(x))
using namespace std;
int n, num[51];
void roll(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
bool a[110], b[110];
bool okay() {
    CLR(a); CLR(b);
    for (int i = 1; i <= n; ++i) {
        if (!a[i+num[i]-1]) a[i+num[i]-1] = 1; else return false;
        if (!b[n-i+num[i]]) b[n-i+num[i]] = 1; else return false;
    }
    return true;
}
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            num[x] = y;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                for (int k = j + 1; k <= n; ++k) {
                    roll(num[i], num[j], num[k]);
                    cnt += okay();
                    roll(num[i], num[j], num[k]);
                    cnt += okay();
                    roll(num[i], num[j], num[k]);
                }
        printf("%d\n", cnt);
    }
    return 0;
}
