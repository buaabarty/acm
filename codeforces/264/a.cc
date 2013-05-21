#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100010];
int dat[100010], n;
int main() {
    scanf("%s", str);
    n = strlen(str);
    int l = 1, r = n;
    for (int i = 0; str[i]; ++i)
        if (str[i] == 'r') dat[l++] = i+1;
        else dat[r--] = i+1;
    for (int i = 1; i <= n; ++i)
        printf("%d\n", dat[i]);
    return 0;
}
