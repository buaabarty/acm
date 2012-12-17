#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int s[3], n, x;
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
        {
            scanf("%d", &x);
            s[j] += x;
        }
    bool flag = true;
    for (int i = 0; i < 3; ++i) if (s[i] != 0){ flag = false; break; }
    if (flag) puts("YES");
        else puts("NO");
    return 0;
}
