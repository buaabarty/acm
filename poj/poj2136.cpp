#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string str;

int main()
{
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                cnt[str[i] - 'A']++;
    }
    int mmax = 0;
    for (int i = 0; i < 26; i++)
        mmax = max(mmax, cnt[i]);
    for (int i = mmax; i >= 1; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] >= i) printf("*");
            else printf(" ");
            if (j < 25) printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c", i + 'A');
        if (i < 25) printf(" ");
    }
    printf("\n");
    return 0;
}
