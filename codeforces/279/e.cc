#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    static char str[1000000 + 9];
    scanf("%s", str);
    int n = strlen(str), ans = 1, last = 0;
    bool inq = 1;
    for (int i = 1; i < n; ++i)
        if (str[i] == '0') {
            if (inq) {
                if (i - 1 > last) ans += 2;
                else ans += 1;
                inq = 0;
            }
        } else if (!inq) {
            inq = 1;
            last = i;
        }
    if (inq) {
        if (n - 1 > last) ans += 2;
        else ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
