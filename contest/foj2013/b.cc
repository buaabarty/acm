#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool same (char x, char y) {
    if (x >= 'A' && x <= 'Z') x += 'a' - 'A';
    if (y >= 'A' && y <= 'Z') y += 'a' - 'A';
    return (x == y);
}
char a[51000], b[51000], d[51000];
char ans[51000];
int la, lb, ld, len;
int next[51000];
int main() {
    while (gets(a)) {
        len = 0;
        memset(ans, 0, sizeof(ans));
        gets(b); gets(d);
        la = strlen(a); lb = strlen(b);
        ld = strlen(d);
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < la; ++i) {
            while (j >= 0 && !same(a[i], a[j+1])) j = next[j];
            if (same(a[i], a[j+1])) ++j;
            next[i] = j;
        }
        j = -1;
        for (int i = 0; i < ld; ++i) {
            ans[len++] = d[i];
            while (j >= 0 && !same(d[i], a[j+1])) j = next[j];
            if (same(d[i], a[j+1])) ++j;
            if (j == la - 1) {
                len -= la;
                for (int k = 0; k < len; ++k)
                    printf("%c", ans[k]);
                printf("%s", b);
                len = 0;
                j = -1;
            }
        }
        for (int i = 0; i < len; ++i)
            printf("%c", ans[i]);
        puts("");
    }
    return 0;
}
