#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    freopen("maze9.in", "w", stdout);
    printf("500 500\n");
    srand(time(0));
    for (int i = 0; i < 500; ++i)
    {
        for (int j = 0; j < 500; ++j)
        {
            int x = rand() % 12;
            if (x >= 9) printf("#");
            else printf("%d", x + 1);
        }
        puts("");
    }
    printf("3\n");
    for (int i = 1; i <= 3; ++i)
        printf("%d %d\n", rand() % 100000, rand() % 100000);
    return 0;
}
