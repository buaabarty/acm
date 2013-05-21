#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ip[1300000];

int main() {
    memset(ip, 1, sizeof(ip));
    ip[1] = 0;
    for (int i = 2; i < 1300000; ++i)
        if (ip[i]) {
            for (int j = i + i; j < 1300000; j += i)
                ip[j] = 0;
        }
    int x, l, r;
    while (scanf("%d", &x), x) {
        l = x, r = x;
        while (!ip[l]) --l;
        while (!ip[r]) ++r;
        printf("%d\n", r-l);
    }
    return 0;
}


