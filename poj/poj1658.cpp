#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t, a, b, c, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if ((b - a == c - b) && (d - c == c - b)) printf("%d %d %d %d %d\n", a, b, c, d, d + (d - c));
        else printf("%d %d %d %d %d\n", a, b, c, d, d * d / c);
    }
    return 0;
}
