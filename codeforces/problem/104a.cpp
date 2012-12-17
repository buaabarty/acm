#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[14];
int main()
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= 11; ++i) f[i] = 4;
    f[10] = 16;
    int n;
    while (~scanf("%d", &n))
    {
        int x = n - 10;
        if (x <= 0) printf("0\n");
        else if (x == 10) printf("%d\n", f[x] - 1);
        else printf("%d\n", f[x]);
    }
    return 0;
}
