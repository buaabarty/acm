#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int x, i;
    for (i = 1; i <= 3; ++i)
    {
        scanf("%d", &x);
        if (x <= 168)
        {
            printf("CRASH %d\n", x);
            return 0;
        }
    }
    printf("NO CRASH\n");
    return 0;
}
