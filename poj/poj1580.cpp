#include <iostream>
#include <cstring>
#include <cstring>
#include <cstdio>
using namespace std;
int ans(char a[], char b[])
{
    int la = strlen(a), lb = strlen(b), res = 0;
    for (int i = 0; i < la; ++i)
        for (int j = 0; j < lb; ++j)
        {
            int x = i, y = j, l = 0;
            while ((x < la) && (y < lb))
            {
                l += (a[x] == b[y]);
                ++x, ++y;
            }
            res = max(res, l);
        }
    return res;
}
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
char a[1024], b[1024];
int main()
{
    while (scanf("%s", a))
    {
        if (a[0] == '-') break;
        scanf("%s", b);
        printf("appx(%s,%s) = ", a, b);
        int x = ans(a, b) * 2;
        int y = strlen(a) + strlen(b);
        int g = gcd(x, y);
        if (g) x /= g, y /= g;
        printf("%d", x);
        if (y != 1) printf("/%d", y);
        puts("");
        //printf("%d %d\n", x, y);

    }
    return 0;
}
