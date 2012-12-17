#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int p, e, x, d, ca = 0;
    while (scanf("%d%d%d%d", &p, &e, &x, &d))
    {
        if (p == -1) break;
        int i;
        for (i = d + 1; ((i - p) % 23) || ((i - e) % 28) || ((i - x) % 33); ++i);
        printf("Case %d: the next triple peak occurs in %d days.\n", ++ca, i - d);
    }
    return 0;
}
