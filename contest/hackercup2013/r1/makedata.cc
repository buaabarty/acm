#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    freopen("input.txt", "w", stdout);
    printf("25\n");
    for (int i = 0; i < 25; ++i) {
        printf("%d %d\n", 10000, 5000);
        for (int j = 1; j <= 10000; ++j) {
            int x = rand() % 2000000000;
            printf("%d%c", x, " \n"[j==10000]);
        }
    }
    return 0;
}
