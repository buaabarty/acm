#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int main() {
    LL T;
    LL s, h, vx, vy;
    cin >> T;
    while (T--) {
        cin >> s >> h >> vx >> vy;
        LL t = s / vx;
        LL dh = vy * t - 5LL * t * t;
        if (dh >= h) puts("good done!");
        else puts("poor Merida!");
    }
    return 0;
}
