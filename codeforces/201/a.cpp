#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int r, x, s = 1;
    scanf("%d", &x);
    for (r = 1; ; r += 2)
        if (((r * r + 1) >> 1) >= x) break;
    printf("%d\n", (x == 3) ? 5 : r);
    return 0;
}
