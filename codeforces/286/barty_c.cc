#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000009
int ans[N];
int n, dat[N];
bool c[N];
int stack[N], top;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dat[i]);
    }
    int t, x;
    scanf("%d", &t);
    memset(c, 0, sizeof(c));
    while (t--) {
        scanf("%d", &x);
        c[x] = 1;
    }
    top = 0;
    for (int i = n; i >= 1; --i)
        if (c[i]) {
            ans[i] = -dat[i];
            stack[++top] = dat[i];
        } else if (dat[i] == stack[top]) {
                ans[i] = dat[i];
                stack[top--] = 0;
        } else {
            ans[i] = -dat[i];
            stack[++top] = dat[i];
        }
    if (top) puts("NO");
    else {
        puts("YES");
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}
