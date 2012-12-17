#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char l, n, x;
int main()
{
    while (scanf("%d", &n))
    {
        if (!n) break;
        l = -1;
        while (n--)
        {
            scanf("%d", &x);
            if (x != l) printf("%d ", x);
            l = x;
        }
        printf("$\n");
    }
    return 0;
}
