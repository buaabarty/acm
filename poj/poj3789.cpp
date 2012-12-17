#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t, x[3], dat[3][6];
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        scanf("\n%d:%d:%d", &x[0], &x[1], &x[2]);
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 6; ++k)
            {
                dat[j][k] = x[j] % 2;
                x[j] = x[j] / 2;
            }
        printf("%d ", ca);
        for (int i = 5; i >= 0; --i)
            for (int j = 0; j < 3; ++j)
                printf("%d", dat[j][i]);
        printf(" ");
        for (int i = 0; i < 3; ++i)
            for (int j = 5; j >= 0; --j)
                printf("%d", dat[i][j]);
        printf("\n");
    }
    return 0;
}
