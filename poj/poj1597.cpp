#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int gcd(int x, int y)
{
    return (x == 0) ? y : gcd(y % x, x);
}
int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF)
    {
        printf("%10d%10d    ", x, y);
        if (gcd(x, y) == 1) printf("Good Choice\n\n");
        else printf("Bad Choice\n\n");
    }
    return 0;
}
