#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, x, y;
int main() {
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &x, &y);
        printf("Case #%d: ", ca);
        if (x > 0) {
            for (int i = 1; i <= x; ++i)
                printf("WE");
        } else if (x < 0) {
            for (int i = 1; i <= -x; ++i)
                printf("EW");
        }
        if (y > 0) {
            for (int i = 1; i <= y; ++i)
                printf("SN");
        } else if (y < 0) {
            for (int i = 1; i <= -y; ++i)
                printf("NS");
        }
        puts("");
    }
    return 0;
}
