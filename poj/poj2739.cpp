#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10000
#define MAXP 1500
using namespace std;
bool isp[MAXN];
int p[MAXN], pl = 0, okay[MAXN], res = 0, d[MAXP], start;
void dfs(int sum, int k)
{
    if (sum == 0){
        res++;
        for (int i = start; i < k; ++i)
            printf("%d ", d[i]);
        printf("\n");
        return;
    }
    if ((k > pl) || (p[k] > sum)) return;
    for (int i = p[k]; i <= sum; i += p[k])
    {
        d[k] = i / p[k];
        dfs(sum - i, k + 1);
    }
}
int main()
{
    memset(isp, true, sizeof(isp));
    memset(p, 0, sizeof(p));
    isp[1] = false;
    for (int i = 2; i < MAXN; ++i)
        if (isp[i]){
            for (int j = i + i; j < MAXN; j += i)
                isp[j] = false;
            p[++pl] = i;
        }
    okay[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        for (int j = 1; j <= pl; ++j)
            if (i >= p[j]) okay[i] |= okay[i - p[j]];
            else break;
    int n;
    while (scanf("%d", &n))
    {
        if (!n) break;
        res = 0;
        for (int i = 1; i <= pl; ++i)
            if (p[i] <= n){
                int s = p[i], j = i;
                while ((s < n) && (j < pl)) s += p[++j];
                if (s == n) res++;
            }
            else break;
        printf("%d\n", res);
    }
    return 0;
}
