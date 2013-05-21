#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int ans[100010];
int main() {
    scanf("%d", &n);
    int st = 1, ed = n;
    while (ed - st + 1 >= 4) {
        ans[st] = st + 1;
        ans[st+1] = ed;
        ans[ed-1] = st;
        ans[ed] = ed-1;
        st += 2; ed -= 2;
    }
    int last = ed - st + 1;
    if (last <= 1) {
        if (last == 1) ans[st] = st;
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i==n]);
    } else puts("-1");
    return 0;
}
