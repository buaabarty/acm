#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define MAXN 100010
using namespace std;
int n, num[MAXN], dat[MAXN], l, r, mid, len;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        for (int i = 1; i <= n + 2; ++i)
            dat[i] = INT_MAX;
        dat[0] = INT_MIN; len = 0;
        for (int i = 1; i <= n; ++i)
        {
            l = 0, r = len + 1;
            while (l < r)
            {
                if (l + 1 == r){
                    if (num[i] > dat[l]) l = r;
                    break;
                }
                mid = (l + r) / 2;
                if (num[i] > dat[mid]) l = mid + 1;
                else r = mid;
            }
            if (l == len + 1) len++;
            dat[l] = num[i];
        }
        if (len) printf("%d\n", len);
        else printf("1\n");
    }
    return 0;
}
