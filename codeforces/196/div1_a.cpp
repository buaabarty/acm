#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, r;
    scanf("%d%d%d", &a, &b, &r);
    printf("%s\n", (min(a, b) >= r * 2) ? "First" : "Second");
    return 0;
}
