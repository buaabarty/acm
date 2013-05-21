#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void gao(int x) {
    while (x) {
        int now = x&127;
        x >>= 7;
        if (x) now |= 128;
        printf("%02X", now);
    }
}
int T;
int olen;
char str[3000000 + 9];
int main() {
    scanf("%d", &T);
    gets(str);
    while (T--) {
        gets(str);
        olen = strlen(str);
        if (!olen) printf("00");
        gao(olen);
        for (int i = 0; str[i]; ++i)
            printf("%X", str[i]);
        printf("\n");
    }
    return 0;
}
