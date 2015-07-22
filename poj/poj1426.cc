#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
int main() {
    int n;
    while (scanf("%d", &n) == 1, n) {
        queue<LL> q;
        if (n == 1) {
            printf("1\n");
            continue;
        }
        q.push(1);
        while (!q.empty()) {
            LL x = q.front();
            q.pop();
            if (x * 10 % n == 0) {
                printf("%lld\n", x * 10);
                break;
            }
            q.push(x * 10);
            if ((x * 10 + 1) % n == 0) {
                printf("%lld\n", x * 10 + 1);
                break;
            }
            q.push(x * 10 + 1);
        }
    }
    return 0;
}
