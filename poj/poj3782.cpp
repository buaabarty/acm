#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 32768
using namespace std;
int t, number, n, num[MAXN];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &number, &n);
        int total = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            total += num[i];
        }
        int now = 0, sum = 0;
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            sum += num[i];
            if (total % sum) continue;
            flag = true;
            now = 0;
            for (int j = i + 1; j <= n; ++j)
            {
                now += num[j];
                if (now > sum){
                    flag = false;
                    break;
                }
                if (now == sum) now = 0;
            }
            if (now) flag = false;
            if (flag){
                printf("%d %d\n", number, sum);
                break;
            }
        }
    }
    return 0;
}
