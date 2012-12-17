#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int t, num[4];
    string str;
    scanf("%d", &t);
    while (t--)
    {
        cin >> str;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 8; ++j)
                num[i] = num[i] * 2 + str[i * 8 + j] - '0';
        for (int i = 0; i < 3; ++i)
            printf("%d.", num[i]);
        printf("%d\n", num[3]);
    }
    return 0;
}
