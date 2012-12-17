#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int r[16], g[16], b[16];
int sqr(int a)
{
    return a * a;
}
double dist(int x, int y, int z, int i)
{
    return sqrt(sqr(x - r[i]) + sqr(y - g[i]) + sqr(z - b[i]));
}
int main()
{
    int x, y, z;
    for (int i = 0; i < 16; ++i)
        scanf("%d%d%d", &r[i], &g[i], &b[i]);
    while (scanf("%d%d%d", &x, &y, &z))
    {
        if (x == -1) break;
        int j = 0;
        for (int i = 0; i < 16; ++i)
            if (dist(x, y, z, i) < dist(x, y, z, j)) j = i;
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, r[j], g[j], b[j]);
    }
    return 0;
}
