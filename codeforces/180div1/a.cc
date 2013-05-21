#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1100], b[1100];
int n, m;
int main() {
    scanf("%s%s", a, b);
    n = strlen(a), m = strlen(b);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; ++i)
        cnta += (a[i] == '1');
    for (int i = 0; i < m; ++i)
        cntb += (b[i] == '1');
    bool flag = (cnta + (cnta&1) >= cntb);
    if (flag) puts("YES");
    else puts("NO");
    return 0;
}
