#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("input.txt", "w", stdout);
    printf("1500\n");
    for (int i = 1; i < 1500; ++i)
        printf("%d %d\n", i, i + 1);
    for (int i = 1; i <= 1500; ++i)
        printf("%d %d\n", i, i);
    return 0;
}
