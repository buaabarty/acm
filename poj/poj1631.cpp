#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 65536
using namespace std;
int n, num[MAXN], dat[MAXN], l, r, len, mid;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(dat, 0x7f, sizeof(dat));
        l = 0;
        len = r = 1;
        dat[l] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            l = 0, r = len + 1;
            while (l < r)
            {
                if (l + 1 == r)
                {
                    if (num[i] > dat[l]) l = r;
                    break;
                }
                mid = (l + r) >> 1;
                if (num[i] > dat[mid]) l = mid + 1;
                else r = mid;
            }
            if (l > len) dat[++len] = num[i];
            else dat[l] = num[i];
        }
        printf("%d\n", len);
    }
    return 0;
}
