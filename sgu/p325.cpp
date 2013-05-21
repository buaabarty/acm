#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define N 1000000
#define LL long long
using namespace std;
LL c[N+10], sum;
int n;
int lowbit(int x)
{
    return (x & (-x));
}
LL getsum(int k)
{
    LL s = 0;
    while (k)
    {
        s += c[k];
        k -= lowbit(k);
    }
    return s;
}
void insert(int k, LL delta)
{
    while (k <= n)
    {
        c[k] += delta;
        k += lowbit(k);
    }
}
char str[N+10];
int l[26], r[26];
vector<int> dat[26];
bool use[N+10];
int main()
{
    memset(use, 0, sizeof(use));
    scanf("%s", str);
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < 26; ++i)
        dat[i].clear();
    for (int i = 0; str[i]; ++i)
        dat[str[i] - 'A'].push_back(i + 1);
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        l[i] = 0;
        r[i] = dat[i].size() - 1;
        cnt += ((r[i] + 1) & 1);
    }
    if (cnt > 1)
    {
        puts("-1");
        return 0;
    }
    n = strlen(str), sum = 0;
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        insert(i, 1LL);
    int ll = 1, rr = n;
    for (int i = 1; i <= n / 2; ++i)
    {
        int t = -1;
        LL nows = 100000000000000LL;
        for (int j = 0; j < 26; ++j)
            if ((r[j] > l[j]) && ((dat[j][l[j]] == ll) || (dat[j][r[j]] == rr)))
            {
                LL left = getsum(dat[j][l[j]] - 1);
                LL right = getsum(n) - getsum(dat[j][r[j]]);
                if (left + right < nows)
                {
                    nows = left + right;
                    t = j;
                }
            }
        if (t == -1)
        {
            flag = false;
            break;
        }
        sum += nows;
        use[dat[t][l[t]]] = 1;
        use[dat[t][r[t]]] = 1;
        while (use[ll] && (ll <= rr)) ++ll;
        while (use[rr] && (rr >= ll)) --rr;
        insert(dat[t][l[t]], -1LL);
        insert(dat[t][r[t]], -1LL);
        l[t]++;
        r[t]--;
    }
    if (!flag) sum = -1LL;
    cout << sum << endl;
    return 0;
}
