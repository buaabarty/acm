#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        puts("a");
    } else if (m == 1 || n < m) {
        puts("-1");
    } else if (m == 2) {
        for (int i = 0; i < n; ++i)
            printf("%c", i % 2 + 'a');
        puts("");
    } else {
        while (n > m) {
            printf("ab");
            n -= 2;
        }
        if (n == m) {
            for (int i = 0; i < m; ++i)
                printf("%c", 'a'+i);
        } else {
            printf("a");
            for (int i = 2; i < m; ++i)
                printf("%c", 'a'+i);
        }
        puts("");
    }
    return 0;
}
