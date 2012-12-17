#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, x, r;
int gcd(int a, int b)
{
    return (a) ? gcd(b % a, a) : b;
}
int main()
{
    while (scanf("%d", &n), n)
    {
        r = 1;
        while (n--)
        {
            scanf("%d", &x);
            if (r < 1000000) r = r / gcd(r, x) * x;
        }
        if (r >= 1000000) printf("Too much money to pay!\n");
        else printf("The CEO must bring %d pounds.\n", r);
    }
    return 0;
}
