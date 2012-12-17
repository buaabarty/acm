#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    char s1[10], s2[10];
    while (t--)
    {
        scanf("%s%s", s1, s2);
        int a = 0, b = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (s2[i] == s1[j])
                {
                    if (i == j) ++a;
                    else ++b;
                }
        printf("%dA%dB\n", a, b);
    }
    return 0;
}
