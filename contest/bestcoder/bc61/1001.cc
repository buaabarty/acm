#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int a[1000];
int b[2000];
int main() {
    while (scanf("%d", &n) == 1) {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[a[i]]++;
        }
        bool find = false;
        for (int i = 1; i <= n; ++i) {
            b[a[i]]--;
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    b[a[j]]--;
                    if (a[i] >= a[j] && b[a[i]-a[j]]) {
                        find = true;
                        break;
                    }
                    b[a[j]]++;
                }
            }
            b[a[i]]++;
        }
        puts(find?"YES":"NO");
    }
    return 0;
}
