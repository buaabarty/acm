#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 20
using namespace std;
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
int main()
{
    char str[MAXN];
    int a, b, c, d, x, y, g;
    while (scanf("%s", str) != EOF)
    {
        a = str[0] - '0';
        b = str[2] - '0';
        c = str[4] - '0';
        d = str[6] - '0';
        if (str[3] == '-') x = a * d - b * c;
        else x = a * d + b * c;
        y = b * d;
        if (x < 0){
            printf("-");
            x = -x;
        }
        g = gcd(x, y);
        x /= g, y /= g;
        if (y == 1) printf("%d\n", x);
        else printf("%d/%d\n", x, y);
    }
    return 0;
}
