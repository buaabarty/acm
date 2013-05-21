#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int T;
    int cnt[256];
    char str[250];
    scanf("%d", &T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        for (int i = 0; str[i]; ++i)
            ++cnt[str[i]];
        int ans = 0;
        for (int i = 0; i < 256; ++i)
            ans += (cnt[i] + 1) / 2;
        printf("%d\n", ans);
    }
    return 0;
}
