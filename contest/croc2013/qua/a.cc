#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int id[1000 + 9];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &id[i]);
        sort(id + 1, id + n + 1);
        bool flag = true;
        id[0] = -1;
        int tot = 0;
        for (int i = 2; i <= n; ++i) if (id[i])
            if (id[i] == id[i-1]) {
                if (id[i-1] == id[i-2]) {
                    flag = false;
                    break;
                }
                ++tot;
            }
        if (flag) printf("%d\n", tot);
        else printf("-1\n");
    }
    return 0;
}
