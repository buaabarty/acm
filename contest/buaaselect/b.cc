#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int x, y, r;
    while (scanf("%d%d%d", &x, &y, &r) == 3) {
        if (x >= 2*r && y >= 2*r) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
