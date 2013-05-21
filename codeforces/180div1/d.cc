#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[2010][1010];
int h, w, k;
int main() {
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 1; i <= 2 * h - 1; ++i)
        scanf("%s", str[i]);
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
    return 0;
}
