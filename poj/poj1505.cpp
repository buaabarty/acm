#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 4096
using namespace std;
long long n, m, num[MAXN];
bool dat[MAXN];
bool okay(long long s)
{
    for (long long i = 1; i <= n; ++i) if (num[i] > s) return false;
    long long now = 0, j = 0;
    for (long long i = 1; i <= n; ++i)
        if (now + num[i] > s){
            now = num[i];
            j++;
        }
        else now += num[i];
    return (j < m);
}
void fill(long long s)
{
    long long now = 0, last = m;
    for (long long i = n; i >= 1; --i)
        if (now + num[i] > s){
            now = num[i];
            dat[i + 1] = true;
            last--;
        }
        else if ((i == last)){
            dat[i] = true;
            last--;
        }
        else now += num[i];
}
int main()
{
    long long t, l, r, mid;
    //freopen("books.in", "r", stdin);
    //freopen("ans.out", "w", stdout);
    scanf("%lld", &t);
    while (t--)
    {
        memset(dat, 0, sizeof(dat));
        memset(num, 0, sizeof(num));
        scanf("%lld%lld", &n, &m);
        l = 0, r = 0;
        for (long long i = 1; i <= n; ++i)
        {
            scanf("%lld", &num[i]);
            r += num[i];
        }
        while (l < r)
        {
            if (l + 1 == r){
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) / 2;
            if (okay(mid)) r = mid;
            else l = mid + 1;
        }
        fill(l);
        dat[1] = false;
        for (long long i = 1; i <= n; ++i)
        {
            if (dat[i]) printf("/ %lld", num[i]);
            else printf("%lld", num[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
