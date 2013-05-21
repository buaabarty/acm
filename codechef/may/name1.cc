#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

int cnt[26];

void add(char *s, int f) {
    for (int i = 0; s[i]; ++i)
        cnt[s[i]-'a'] += f;
}

char str[100000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        add(str, 1);
        scanf("%s", str);
        add(str, 1);
        int n;
        scanf("%d", &n);
        while (n--) {
            scanf("%s", str);
            add(str, -1);
        }
        bool flag = true;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] < 0) {
                flag = false;
                break;
            }
        puts((flag)?"YES":"NO");
    }
    return 0;
}
