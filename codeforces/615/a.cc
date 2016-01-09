#include <iostream>
#include <cstdio>
using namespace std;
bool s[100];
int n, m, x, y;
int main() {
    scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        while (x--) {
            scanf("%d", &y);
            s[y - 1] = 1;
        }
    }
    bool check = true;
    for (int i = 0; i < m; ++i) {
        check &= s[i];
    }
    puts(check ? "YES" : "NO");
    return 0;
}
