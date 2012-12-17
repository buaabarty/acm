#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1024
#define L long long
using namespace std;
L gcd(L a, L b)
{
    return (b) ? gcd(b, a % b) : a;
}
L lcm(L a, L b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    int num[MAXN], n;
    bool use[MAXN];
    while (scanf("%d", &n) != EOF)
    {
        L res = 1;
        memset(use, false, sizeof(use));
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        for (int i = 1; i <= n; ++i)
            if (!use[i]){
                int j = i, l = 1;
                while (num[j] != i){
                    use[j] = true;
                    ++l;
                    j = num[j];
                }
                res = lcm(res, (L) l);
            }
        cout << res << endl;
    }
    return 0;
}
