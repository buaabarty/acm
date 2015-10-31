#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int t, n;
string s[500];
bool okay(string a, string b) {
    return (a.find(b) == -1);
}
int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca) {
        scanf("%d", &n);
        int res = -1;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        bool f[500];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) if (!i || f[i]) {
            string cmp = s[i];
            for (int j = i + 1; j < n; ++j) {
                if (!f[j]) {
                    if (okay(s[j], cmp)) {
                        f[j] = 1;
                    } else {
                        cmp = s[j];
                    }
                }
            }
            if (i && f[i]) res = i + 1;
        }
        printf("Case #%d: %d\n", ca, res);
    }
    return 0;
}
