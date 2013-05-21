#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL f[100], c[10][10];
LL p2[20];
int main() {
    c[0][0] = 1;
    for (int i = 1; i < 10; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    p2[0] = 1;
    for (int i = 1; i < 20; ++i) p2[i] = p2[i-1] * 2;
    f[1] = 1;
    for (int i = 2; i <= 4; ++i) {
        f[i] = p2[(i-1)*i/2];
        for (int j = 0; j < i - 1; ++j)
            f[i] -= c[i-1][j] * p2[c[i-j-1][2]] * f[j+1];
        cout << f[i] << endl;
    }
    return 0;
}
