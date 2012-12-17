#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t, h, m;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d:%d", &h, &m);
        printf("%d\n", (m) ? 0 : ((h + 11) % 24) + 1);
    }
    return 0;
}
