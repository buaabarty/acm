#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
int random(int x)
{
    return (rand() % x) + 1;
}
int n = 100000;
int lim = 32767;
int limk = 32;
int main()
{
    srand(time(0));
    freopen("tower9.in", "w", stdout);
    printf("%d ", n);
    printf("%d ", random(n / 2));
    printf("%d %d\n", random(limk), random(lim));
    for (int i = 1; i < n; ++i)
        printf("%d ", random(lim));
    printf("%d\n", random(lim));

    return 0;
}
