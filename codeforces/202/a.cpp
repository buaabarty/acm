#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char str[30];
int main() {
    scanf("%s", str);
    char c = 0;
    for (int i = 0; str[i]; ++i) c = max(c, str[i]);
    for (int i = 0; str[i]; ++i) if (c == str[i]) putchar(c);
    puts("");
    return 0;
}
