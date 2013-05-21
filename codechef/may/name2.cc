#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

bool okay(char *x, char *y) {
    int n = strlen(x);
    int m = strlen(y), j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && y[j] != x[i]) ++j;
        if (y[j] != x[i]) return false;
        ++j;
    }
    return true;
}

int T;
char a[100000], b[100000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", a, b);
        if (okay(a, b) || okay(b, a)) puts("YES");
        else puts("NO");

    }
    return 0;
}
