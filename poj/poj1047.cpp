#include <iostream>
#include <cstdio>
#include <cstring>
#define N 64
using namespace std;
int num[N], n, now[N], cnt[10], nowc[N];
char str[N];
int main()
{
    while (~scanf("%s", str))
    {
        memset(cnt, 0, sizeof(cnt));
        n = strlen(str);
        for (int i = 1; i <= n; ++i)
            num[i] = str[n - i] - '0';
        for (int i = 1; i <= n; ++i) cnt[num[i]]++;
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) now[j] = num[j] * i;
            for (int j = 1; j <= n; ++j)
            {
                now[j + 1] += (now[j] / 10);
                now[j] %= 10;
            }
            memset(nowc, 0, sizeof(nowc));
            for (int j = 1; j <= n; ++j) nowc[now[j]]++;
            for (int j = 0; j < 10; ++j)
                if (nowc[j] != cnt[j])
                {
                    flag = false;
                    break;
                }
        }
        if (flag) printf("%s is cyclic\n", str);
        else printf("%s is not cyclic\n", str);
    }
    return 0;
}
