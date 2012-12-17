#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int* x = new int;
int main()
{
    while (scanf("%d", x))
    {
        if (!(*x)) break;
        if (*x % 2) printf("%d\n", *x - 1);
        else printf("No Solution!\n");
    }
    delete x;
    return 0;
}
