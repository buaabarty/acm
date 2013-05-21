#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T, cnt[26];
    char str[511];
    scanf("%d", &T);
    gets(str);
    for (int ca = 1; ca <= T; ++ca) {
        memset(cnt, 0, sizeof(cnt));
        gets(str);
        for (int i = 0; str[i]; ++i)
            if (str[i]>='A' && str[i]<='Z') cnt[str[i]-'A']++;
            else if (str[i]>='a' && str[i]<='z') cnt[str[i]-'a']++;
        sort(cnt, cnt+26);
        int tot = 0;
        for (int i = 0; i < 26; ++i)
            tot += cnt[i] * (i + 1);
        printf("Case #%d: %d\n", ca, tot);
    }
    return 0;
}
