#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int ca = 0, n0, n1, n2, n3, n4;
    while (scanf("%d", &n0), n0)
    {
        printf("%d. ", ++ca);
        n1 = 3 * n0;
        if (n1 & 1) printf("odd");
        else printf("even");
        n2 = (n1 + 1) >> 1;
        n3 = 3 * n2;
        n4 = n3 / 9;
        printf(" %d\n", n4);
    }
    return 0;
}
