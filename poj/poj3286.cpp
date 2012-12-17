#include <iostream>
#include <cstdio>
#include <cstring>
#define N 11
using namespace std;
void solve(long long s, long long ans[]){
    int i, j, k;
    if (s < 0) return;
    long long rgt = 0, id = 1;
    ans[0] += 1;
    while (s > 0)
    {
        int now = s % 10;
        s /= 10;
        for (i = 0; i < 10; i++)
        {
            if (now > i)
            {
                ans[i] += s * id;
                if (i) ans[i] += id;
            }
            else if (now == i)
            {
                if (s && i == 0)
                    ans[i] += (s - 1) * id + rgt + 1;
                else if (i > 0)
                    ans[i] += s * id + rgt + 1;
            }
            else if (now < i) ans[i] += s * id;
        }
        rgt += now * id;
        id *= 10;
    }
}
long long ans[N], s, t;
int main()
{
    while (scanf("%lld%lld", &s, &t))
    {
        if (t < 0) break;
        if (s > t) swap(s, t);
        memset(ans, 0, sizeof(ans));
        solve(s - 1, ans);
        for (int i = 0; i < 10; ++i) ans[i] = -ans[i];
        solve(t, ans);
        printf("%lld\n", ans[0]);
    }
    return 0;
}
