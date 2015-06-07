#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < n; i += 2) {
            printf("%c", str[i]);
        }
        printf("\n");
        for (int i = n - 1; i > 0; i -= 2) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
