#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#define MAXN 128
using namespace std;
char dat[MAXN][MAXN];
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];
int cnt[MAXN];
bool app[MAXN];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        memset(app, 0, sizeof(app));
        memset(x1, 0x7f, sizeof(x1));
        memset(y1, 0x7f, sizeof(y1));
        memset(x2, 0, sizeof(x2));
        memset(y2, 0, sizeof(y2));
        if (n + m == 0) break;
        for (int i = 1; i <= n; ++i)
        {
            scanf("\n");
            for (int j = 1; j <= m; ++j)
            {
                scanf("%c", &dat[i][j]);
                if (isalpha(dat[i][j])){
                    x1[dat[i][j] - 'A'] = min(x1[dat[i][j] - 'A'], i);
                    y1[dat[i][j] - 'A'] = min(y1[dat[i][j] - 'A'], j);
                    x2[dat[i][j] - 'A'] = max(x2[dat[i][j] - 'A'], i);
                    y2[dat[i][j] - 'A'] = max(y2[dat[i][j] - 'A'], j);
                    app[dat[i][j] - 'A'] = true;
                }
            }
        }
        for (int i = 0; i < 26; ++i)
            if (app[i]){
                if ((x2[i] < x1[i] + 2) || (y2[i] < y1[i] + 2)) continue;
                //printf("%c:", i + 'A');
                int x, y;
                bool flag = true;
                for (x = x1[i], y = y1[i]; x <= x2[i]; ++x) if (dat[x][y] != (i + 'A')) flag = false;
                //printf("%d ", flag);
                for (x = x1[i], y = y1[i]; y <= y2[i]; ++y) if (dat[x][y] != (i + 'A')) flag = false;
                //printf("%d ", flag);
                for (x = x1[i], y = y2[i]; x <= x2[i]; ++x) if (dat[x][y] != (i + 'A')) flag = false;
                //printf("%d ", flag);
                for (x = x2[i], y = y1[i]; y <= y2[i]; ++y) if (dat[x][y] != (i + 'A')) flag = false;
                //printf("%d ", flag);
                for (x = x1[i] + 1; x < x2[i]; ++x)
                    for (y = y1[i] + 1; y < y2[i]; ++y)
                        if (dat[x][y] != '.') flag = false;
                //printf("%d ", flag);
                if (flag) printf("%c", i + 'A');
            }
        printf("\n");
    }
    return 0;
}
