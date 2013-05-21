#include <cstdio>
#include <cstring>
#include <climits>

#define maxN 100000

using namespace std;

int n, m, a[maxN], f[maxN], b[maxN], g[maxN + 1], c[maxN + 1];

int main()
{
    freopen("chan.in", "r", stdin);
    freopen("chan.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i)
        scanf("%d", a + i);
    m = 0;
    g[0] = INT_MIN;
    for(int i = 1; i <= n; ++ i)
        g[i] = INT_MAX;
    for(int i = 0; i < n; ++ i)
    {
        int low = 0, upp = n;
        while(low < upp)
        {
            int mid = (low + upp + 1) >> 1;
            if(g[mid] < a[i])
                low = mid;
            else
                upp = mid - 1;
        }
        f[i] = low + 1;
        if(a[i] < g[f[i]])
            g[f[i]] = a[i];
        if(f[i] > m)
            m = f[i];
    }
    g[0] = INT_MAX;
    for(int i = 1; i <= n; ++ i)
        g[i] = INT_MIN;
    for(int i = n - 1; i > -1; -- i)
    {
        int low = 0, upp = n;
        while(low < upp)
        {
            int mid = (low + upp + 1) >> 1;
            if(a[i] < g[mid])
                low = mid;
            else
                upp = mid - 1;
        }
        b[i] = low + 1;
        if(a[i] > g[b[i]])
            g[b[i]] = a[i];
    }
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; ++ i)
        if(f[i] + b[i] == m + 1)
            c[f[i]] ++;
    int t = 0;
    for(int i = 0; i < n; ++ i)
        t += (f[i] + b[i] == m + 1 && c[f[i]] == 1);
    printf("%d\n", t);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
