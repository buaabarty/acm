#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    freopen("data.in", "w", stdout);
    printf("100000\n");
    for (int i = 1; i <= 100000; ++i)
    {
        printf("%d ", rand());
    }
    puts("");
    return 0;
}
