#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXL 1024
using namespace std;
int main()
{
    int a, b, s, x;
    char str[MAXL];
    while (scanf("%d%d", &a, &b))
    {
        if (a + b == 0) break;
        s = 0;
        for (int i = 1; i <= a; ++i)
        {
            scanf("%s%d", &str, &x);
            s += x;
        }
        printf("%d\n", b * 3 - s);
    }
    return 0;
}
