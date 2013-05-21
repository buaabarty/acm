#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int x, y, d, n, t;
char a[2000000+10];
char b[2000000+10];
int main() {
    scanf("%d%s%s", &n, a, b);
    x = 0, y = 0, d = 0, t = 0;
    for (int i = 0; i < 2 * n; ++i)
        if (a[i] == '1' && b[i] == '1') ++d;
        else if (a[i] == '1' && b[i] == '0') ++x;
        else if (a[i] == '0' && b[i] == '1') ++y;
        else ++t;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        //printf("%d %d %d %d\n", x, y, d, t);
        if (d > 0) {
            --d;
            ++sx;
        } else if (x > 0) {
            --x; ++sx;
        } else if (y > 0) {
            --y;
        } else --t;
        //printf("%d %d %d %d\n\n", x, y, d, t);
        if (d > 0) {
            --d;
            ++sy;
        } else if (y > 0) {
            --y; ++sy;
        } else if (x > 0) {
            --x;
        } else --t;
    }
    if (sx > sy) puts("First");
    else if (sx == sy) puts("Draw");
    else puts("Second");
    return 0;
}
