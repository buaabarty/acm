#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int n, num[100010], m;
bool okay(int limit)
{
    int cnt = 0, now = 0;
    for (int i = 1; i <= n; ++i)
    {
        now += num[i];
        if (now > limit)
        {
            now = num[i];
            cnt++;
        }
    }
    return (cnt < m);
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int left = -INT_MAX, right = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            left = max(left, num[i]);
            right += num[i];
        }
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (!okay(left)) left = right;
                break;
            }
            int mid = (left + right) >> 1;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        printf("%d\n", left);
    }
    return 0;
}
