#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int d, n, x, s = 0;
int main()
{
    scanf("%d%d", &d, &n);
    while (n--)
    {
        scanf("%d", &x);
        if (n) s += (d - x);
    }
    printf("%d\n", s);
    return 0;
}
