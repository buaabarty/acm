#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 16
using namespace std;
int main()
{
    int t, num[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i <= 10; ++i)
            scanf("%d", &num[i]);
        sort(num + 1, num + 11);
        printf("%d %d\n", num[0], num[8]);
    }
    return 0;
}
