#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int get(int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x & 1) return get(x / 2) + get(x / 2 + 1);
    return get(x / 2);
}
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", get(n));
    }
    return 0;
}
