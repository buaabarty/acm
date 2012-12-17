#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 65536
using namespace std;
string str;
int f[MAXN];
int main()
{
    while (cin >> str)
    {
        if (str == "0") break;
        int len = str.length();
        memset(f, 0, sizeof(f));
        f[0] = f[1] = 1;
        for (int i = 2; i <= len; ++i)
        {
            f[i] += f[i - 1];
            if ((str[i - 2] == '0') || (str[i] == '0') || (str[i - 1] == '0')) continue;
            if ((str[i - 2] - '0') * 10 + str[i - 1] - '0' <= 26) f[i] += f[i - 2];
            //printf("  %d:%d\n", i, f[i]);
        }
        printf("%d\n", f[len]);
    }
    return 0;
}
