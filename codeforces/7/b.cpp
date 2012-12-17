#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m, t, nowid;
char str[100];
int dat[110];
int main()
{
    memset(dat, 0, sizeof(dat));
    scanf("%d%d", &t, &m);
    nowid = 0;
    for (int i = 1; i <= t; ++i)
    {
        int para;
        scanf("%s", str);
        if (str[0] == 'a')
        {
            scanf("%d", &para);
            bool find = false;
            for (int j = 1; j <= m; ++j)
            {
                bool flag = true;
                for (int k = 1; k <= para; ++k)
                    if (dat[j + k - 1] || (j + k - 1 > m))
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    nowid++;
                    for (int k = 1; k <= para; ++k)
                        dat[j + k - 1] = nowid;
                    find = true;
                    break;
                }
            }
            if (!find) puts("NULL");
            else printf("%d\n", nowid);
        }
        else if (str[0] == 'e')
        {
            scanf("%d", &para);
            if ((para <= 0) || (para > nowid)) puts("ILLEGAL_ERASE_ARGUMENT");
            else
            {
                bool find = false;
                for (int j = 1; j <= m; ++j)
                    if (dat[j] == para)
                    {
                        find = true;
                        dat[j] = 0;
                    }
                if (!find) puts("ILLEGAL_ERASE_ARGUMENT");
            }
        }
        else
        {
            for (int j = 1; j <= m; ++j)
                if (dat[j] == 0)
                {
                    for (int k = j + 1; k <= m; ++k)
                        if (dat[k] > 0)
                        {
                            swap(dat[j], dat[k]);
                            break;
                        }
                }
        }
    }
    return 0;
}
