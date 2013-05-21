#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int kong[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
char str[100];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int ans = 0;
        for (int i = 0; str[i]; ++i)
            ans += kong[str[i]-'0'];
        printf("%d\n", ans);
    }
    return 0;
}
