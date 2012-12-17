#include <iostream>
#include <cstdio>
#include <cstring>
#define N 32768
#define M 3513
using namespace std;
int n, prime[M], cnt;
bool pp[N];
int main()
{
    memset(pp, 1, sizeof(pp));
    pp[1] = cnt = 0;
    for (int i = 2; i < N; ++i)
        if (pp[i])
        {
            prime[++cnt] = i;
            for (int j = i + i; j < N; j += i)
                pp[j] = 0;
        }
    while (~scanf("%d", &n), n)
    {
        int res = 0;
        for (int i = 1; prime[i] <= n / 2; ++i)
            if (pp[n - prime[i]]) ++res;
        printf("%d\n", res);
    }
    return 0;
}
