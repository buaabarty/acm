#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            putchar('a' + (i % 4));
        puts("");
    }
    return 0;
}
