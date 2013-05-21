#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m), (n + m))
    {
        if ((n & 1) && (m & 1)) puts("What a pity!");
        else puts("Wonderful!");
    }
    return 0;
}
