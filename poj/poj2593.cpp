#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 100010
#define MAX_INT 1000000000
using namespace std;
int num[MAX_N], s1[MAX_N], s2[MAX_N];
int t, n;
int main()
{
    //scanf("%d", &t);
    while (scanf("%d", &n))
    {
        if (!n) break;
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        int ss = 0;
        s1[0] = -MAX_INT;
        for (int i = 1; i <= n; i++)
        {
            ss += num[i];
            s1[i] = max(ss, s1[i - 1]);
            if (ss < 0) ss = 0;
        }
        ss = 0;
        s2[n + 1] = -MAX_INT;
        for (int i = n; i >= 1; i--)
        {
            ss += num[i];
            s2[i] = max(ss, s2[i + 1]);
            if (ss < 0) ss = 0;
        }
        int res = -MAX_INT;
        for (int i = 0; i <= n; i++)
        {
            //if (s1[i] != -MAX_INT) res = max(res, s1[i]);
            //if (s2[i + 1] != -MAX_INT) res = max(res, s2[i + 1]);
            res = max(res, s1[i] + s2[i + 1]);
        }
        printf("%d\n", res);
    }
    return 0;
}
