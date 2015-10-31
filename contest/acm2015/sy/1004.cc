#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, a, b;
int gcd(int x, int y) {
    return x?gcd(y%x, x):y;
}
int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca) {
        scanf("%d%d%d", &n, &a, &b);
        int cnt = n / gcd(a, b);
        printf("Case #%d: %s\n", ca, (cnt&1)?"Yuwgna":"Iaka");
    }
    return 0;
}
