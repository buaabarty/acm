#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool cango(char c) {
    if (c == 'M' || c=='F') return false;
    else return true;
}
void gao(char x, char y) {
    if (!cango(x)) {
        puts("Error");
        return ;
    } else if (y == 'F') {
        puts("Bingo");
        return ;
    } else if (x == 'B' || y == 'B') {
        puts("0");
        return ;
    } else if (y == 'M') {
        if (x == '9') puts("1");
        else puts("-1");
        return ;
    } else if (x < y) puts("1");
    else if (x == y) puts("0");
    else puts("-1");
}

int main() {
    char a[10], b[10];
    while (scanf("%s%s", a, b) == 2) {
        gao(a[0], b[0]);
    }
    return 0;
}
