#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a, b, c;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", (a*c/b) + (bool)((a*c)%b) - c);
    return 0;
}
