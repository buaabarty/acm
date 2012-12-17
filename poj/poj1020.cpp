#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 32
using namespace std;
int s, n, cnt[N], ss, h[N];
bool dfs(int v)
{
    if (v == n + 1) return true;
    int md = 0, mt;
    for (int i = 1; i <= s; ++i)
        if (h[i] > md)
        {
            md = h[i]; mt = i;
        }
    for (int i = 10; i >= 1; --i)
        if (cnt[i] && (md >= i) && (mt + i - 1 <= s))
        {
            int j = mt;
            for (; j <= mt + i - 1; ++j)
                if (h[j] < md) break;
            if (j > mt + i - 1)
            {
                cnt[i]--;
                for (int k = mt; k <= mt + i - 1; ++k) h[k] -= i;
                if (dfs(v + 1)) return true;
                cnt[i]++;
                for (int k = mt; k <= mt + i - 1; ++k) h[k] += i;
            }
        }
    return false;
}
int main()
{
    int t, x;
    scanf("%d", &t);
    while (t--)
    {
        ss = 0;
        scanf("%d%d", &s, &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            ss += x * x;
            cnt[x]++;
        }
        if (ss != s * s) printf("HUTUTU!\n");
        else{
            for (int i = 1; i <= s; ++i) h[i] = s;
            if (dfs(1)) printf("KHOOOOB!\n");
            else printf("HUTUTU!\n");
        }
    }
    return 0;
}
