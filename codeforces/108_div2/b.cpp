#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
int n, num[N];
int main()
{
//    freopen("data.in", "r", stdin);
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
        sort(num, num + n);
        bool flag = false;
        for (int i = 1; i < n; ++i)
            if ((num[i] > num[i - 1]) && (num[i] < 2 * num[i - 1]))
            {
                flag = true;
                break;
            }
        if (flag) puts("YES");
        else puts("NO");
    }

    return 0;
}

