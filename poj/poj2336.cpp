#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2048
using namespace std;
int n, t, m, f[N], s[N], time[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &t, &m);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &time[i]);
        memset(f, 0x7f, sizeof(f));
        memset(s, 0x7f, sizeof(s));
        f[0] = s[0] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j <= m; ++j)
            {
                if (j > i + n) break;
                int nt = max(f[i], time[j]) + 2 * t;
                if (nt < f[j])
                {
                    f[j] = nt;
                    s[j] = s[i] + 1;
                }
                else if (nt == f[j]) s[j] = min(s[j], s[i] + 1);
            }
        printf("%d %d\n", f[m] - t, s[m]);
    }
    return 0;
}
