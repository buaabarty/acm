#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 64
using namespace std;
int n, num[MAXN], ca = 0;
int main()
{
    while (scanf("%d", &n), n)
    {
        int ave = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            ave += num[i];
        }
        ave /= n;
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (num[i] > ave) res += num[i] - ave;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++ca, res);
    }
    return 0;
}
