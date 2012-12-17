#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXL 1024
using namespace std;
int main()
{
    int s, dat[26];
    char str[MAXL];
    while (scanf("%d", &s))
    {
        if (s == 0) break;
        scanf("%s", str);
        int l = strlen(str);
        memset(dat, 0, sizeof(dat));
        int now = 0, cnt = 0;
        for (int i = 0; i < l; ++i)
        {
            if (dat[str[i] - 'A'] == 1)
            {
                dat[str[i] - 'A'] = 0;
                now--;
            }
            else if (dat[str[i] - 'A'] == 0)
            {
                dat[str[i] - 'A'] = 1;
                if (now == s)
                {
                    cnt++;
                    dat[str[i] - 'A'] = -1;
                }
                else now++;
            }
        }
        if (cnt == 0) printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n", cnt);

    }
    return 0;
}
