#include <stdio.h>
#include <string.h>
#define MAXN 32768
#define MAXL 100000
int d[MAXN], x, opr[MAXN], last[MAXN], i, j, n, m;
int num[10];
int q[MAXL], l, r, find;
int res[MAXN], rl = 0;
int main()
{
    int endd = 0;
    while ((scanf("%d%d", &n, &m) != EOF))
    {
        memset(q, 0, sizeof(q));
        memset(num, 0, sizeof(num));
        memset(opr, 0, sizeof(opr));
        memset(last, 0, sizeof(last));
        memset(d, 0x7f, sizeof(d));
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", &x);
            num[x] = 1;
        }
        if ((n == 0) || (m == 0)){
            printf("0\n");
            continue;
        }
        l = 1, r = 0;
        find = 0;
        for (i = 1; i < 10; ++i)
            if ((num[i]) && (d[i % n] > 1)){
                d[i % n] = 1;
                q[++r] = i % n;
                last[r] = 0;
                opr[r] = i;
                if (i % n == 0){
                    find = 1;
                    break;
                }
            }
        while ((l <= r) && (!find)){
            x = q[l];
            if (d[x] > 500) break;
            for (i = 0; i < 10; ++i)
                if ((num[i]) && (d[x] + 1 < d[(x * 10 + i) % n])){
                    d[(x * 10 + i) % n] = d[x] + 1;
                    q[++r] = (x * 10 + i) % n;
                    opr[r] = i;
                    last[r] = l;
                    if (((x * 10 + i) % n) == 0){
                        find = 1;
                        break;
                    }
                }
            if (find) break;
            l++;
        }

        if (!find) printf("0\n");
        else{
            i = r;
            rl = 0;
            while (i)
            {
                res[++rl] = opr[i];
                i = last[i];
            }
            for (i = rl; i >= 1; --i)
                printf("%d", res[i]);
            printf("\n");
        }

    }
    return 0;
}
