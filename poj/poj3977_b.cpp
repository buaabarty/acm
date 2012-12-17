#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define INT_MAX 1000000000000000LL
#define N 524288
#define S 32
using namespace std;
LL a[N], b[N], n, sa[N], sb[N], la, lb;
void dfs(LL num[], LL res[], LL idx, LL s, LL deep, LL len)
{
    if (deep == (len + 1))
    {
        res[idx] = s;
        return;
    }
    dfs(num, res, idx, s, deep + 1, len);
    dfs(num, res, idx + (1 << (deep - 1)), s + num[deep], deep + 1, len);
}
struct data
{
    LL d, t;
}res, da[N], db[N];
LL num[N];
LL lowbit(LL x)
{
    return x & (x ^ (x - 1));
}
LL cnt(LL x)
{
    LL s = 0;
    while (x)
    {
        s++;
        x -= lowbit(x);
    }
    return s;
}
LL iabs(LL x)
{
    return (x > 0) ? x : -x;
}
void solve(LL x, LL c)
{
//    printf("%lld %lld\n", x, c);
    LL l = 0, r = lb, mid, ns, nc;
    while (l < r)
    {
        if (l + 1 == r)
        {
            if (db[r].d < -x) l = r;
            break;
        }
        mid = (l + r + 1) / 2;
        if (db[mid].d < -x) l = mid;
        else r = mid - 1;
    }
//    printf("    %lld\n", l);
    LL templ = l;
//        printf("%lld ", l);
    for (LL i = max(l - 10, 1LL); i <= min(l + 10, lb); ++i)
    {
        ns = x + db[i].d;
        nc = c + db[i].t;
        if (iabs(ns) < res.d)
        {
            res.d = ns;
            res.t = nc;
        }
        else if ((ns == res.d) && (nc < res.t)) res.t = nc;
    }
}
bool cmp(data a, data b)
{
    return a.d < b.d;
}
int main()
{
    while (~scanf("%lld", &n), n)
    {
        for (LL i = 1; i <= n; ++i) scanf("%lld", &num[i]);
        la = n / 2;
        lb = n / 2 + (n & 1);
        for (LL i = 1; i <= la; ++i) a[i] = num[i];
        for (LL i = 1; i <= lb; ++i) b[i] = num[i + la];
        dfs(a, sa, 0, 0, 1, la);
        dfs(b, sb, 0, 0, 1, lb);
        la = (1 << la) - 1;
        lb = (1 << lb) - 1;
//        puts("HELLO");
        for (LL i = 1; i <= la; ++i)
        {
            da[i].d = sa[i];
            da[i].t = cnt(i);
//            printf("%lld %lld\n", da[i].d, da[i].t);
        }
//        printf("\n\n\n");
        for (LL i = 1; i <= lb; ++i)
        {
            db[i].d = sb[i];
            db[i].t = cnt(i);
        }
        sort(da + 1, da + la + 1, cmp);
        sort(db + 1, db + lb + 1, cmp);
        for (LL i = 1; i <= la; ++i)
        {
//            printf("%lld %lld\n", da[i].d, da[i].t);
        }
        res.d = INT_MAX;
        for (LL i = 1; i <= la; ++i)
            if (iabs(da[i].d) <= res.d)
            {
                if (iabs(da[i].d) < res.d)
                {
                    res.d = iabs(da[i].d);
                    res.t = da[i].t;
                }
                else if (da[i].t < res.t) res.t = da[i].t;
            }
        for (LL i = 1; i <= lb; ++i)
            if (iabs(db[i].d) <= res.d)
            {
                if (iabs(db[i].d) < res.d)
                {
                    res.d = iabs(db[i].d);
                    res.t = db[i].t;
                }
                else if (da[i].t < res.t) res.t = db[i].t;
            }
//        cout << res.d << " " << res.t << endl;
//        for (int i = 1; i <= la; ++i)
//            cout << sa[i] << " "; cout << endl;
//        for (int i = 1; i <= lb; ++i)
//            cout << sb[i] << " "; cout << endl;
        db[0].d = -INT_MAX;
        db[lb + 1].d = INT_MAX;
        for (LL i = 1; i <= la; ++i)
            solve(da[i].d, da[i].t);
        printf("%lld %lld\n", res.d, res.t);

    }
    return 0;
}
