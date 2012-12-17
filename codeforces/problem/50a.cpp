#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int x, y;
    while (~scanf("%d%d", &x, &y))
    {
        printf("%d\n", (x * y) >> 1);
    }
    return 0;
}
