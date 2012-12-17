#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, s, x;
int main()
{
    while (~scanf("%d", &n))
    {
        s = 0;
        while (n--)
        {
            scanf("%d", &x);
            s ^= x;
        }
        if (!s) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
