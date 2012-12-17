#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int gen(int x)
{
    int s = x;
    while (x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}
int main()
{
    bool p[MAXN];
    memset(p, true, sizeof(p));
    for (int i = 1; i <= 10000; ++i)
        p[gen(i)] = false;
    for (int i = 1; i <= 10000; ++i)
        if (p[i]) printf("%d\n", i);
    return 0;
}
