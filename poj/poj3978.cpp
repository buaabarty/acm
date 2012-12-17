#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1000000
using namespace std;
bool isprime(int x)
{
    //if (x < 0) x = -x;
    if (x <= 1) return false;
    if (x == 2) return true;
    for (int i = 2; i <= (int)(sqrt((double)x) + 1); ++i)
        if (x % i == 0) return false;
    return true;
}
int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y))
    {
        if ((x == -1) && (y == -1)) break;
        int sum = 0;
        for (int i = x; i <= y; ++i)
            if (isprime(i)) sum++;
        printf("%d\n", sum);
    }
    return 0;
}
