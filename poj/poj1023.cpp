#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL n, len, l, res[128];
char op[128];
int main()
{
    LL T; scanf("%lld", &T);
    while (T--)
    {
        l = 0;
        scanf("%lld%s%lld", &len, op, &n);
        for (LL i = len - 1; i >= 0; --i)
        {
            if ((n % 2 == 1) || (n % 2 == -1))
            {
                if (op[i] == 'p') n--;
                else n++;
                res[++l] = 1;
            }
            else res[++l] = 0;
            n >>= 1;
        }
        if (n) puts("Impossible");
        else
        {
            for (LL i = l; i >= 1; --i) printf("%lld", res[i]);
            puts("");
        }

    }
    return 0;
}
