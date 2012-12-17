#include <iostream>
#include <cstdio>
using namespace std;
int getsum(int x)
{
    int s = 0;
    for (int i = 1; i <= x; ++i)
        if (!(x % i)) ++s;
    return s;
}
int main()
{
    int T, n, s; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i <= n; ++i)
            if (getsum(i) & 1) ++s;
        printf("%d\n", s);
    }
    return 0;
}
