#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t, n, a, b, c, d;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        scanf("%d", &n);
        a = n / 25;
        n = n % 25;
        b = n / 10;
        n = n % 10;
        c = n / 5;
        n = n % 5;
        d = n;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", ca, a, b, c, d);
    }
    return 0;
}
