#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int x;
    while (~scanf("%d", &x))
    {
        if ((x > 2) && !(x & 1)) printf("YES\n");
        else printf("NO\n");
    }
}
