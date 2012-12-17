#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("test.in", "w", stdout);
    printf("100 100\n");
    for (int i = 1; i <= 100; ++i)
    {
        int x = rand() * 6 - 100000;
        printf("%d ", x);
    }
    printf("\n");
    for (int i = 1; i <= 100; ++i)
    {
        int x = rand() / 32767 * 100, y = rand() / 32767 * 100;
        printf("%d %d\n", x, y);
    }
    fclose(stdout);
    return 0;
}
