#include <iostream>
#include <cstdio>
using namespace std;
int n, s;
int main()
{
    while (~scanf("%d", &n))
    {
        s = 0;
        for (int j = 1; j <= n; ++j)
            if ((n % j == 0) && (j & 1)) s++;
        printf("%d\n", s);
    }
    return 0;
}
