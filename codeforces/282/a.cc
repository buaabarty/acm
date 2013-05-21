#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int x = 0, n;
char str[100];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        if (str[0] == '-') x--;
        else if (str[0] == '+') x++;
    }
    return 0;
}
