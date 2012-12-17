#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int k, num[10][10];
    while (~scanf("%d", &k))
    {
        for (int i = 1; i <= k; ++i) num[i][i] = 1;
        int cnt;
        for (int i = 1; i < k; ++i)
        {
            cnt = i * 2;
            if (i % 2)
            {
                for (int j = i + 1; j <= k; ++j)
                {
                    num[i][j] =
                }
            }
        }
    }
    return 0;
}
