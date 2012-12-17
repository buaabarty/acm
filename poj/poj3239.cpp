#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, k;
    while (scanf("%d", &n), n)
    {
        if ((n % 6 != 2) && (n % 6 != 3))
        {
            if (n & 1)
            {
                for (int i = 2; i <= n - 1; i += 2) printf("%d ", i);
                for (int i = 1; i < n; i += 2) printf("%d ", i);
                printf("%d\n", n);
            }
            else
            {
                for (int i = 2; i <= n; i += 2) printf("%d ", i);
                for (int i = 1; i < n - 1; i += 2) printf("%d ", i);
                printf("%d\n", n - 1);
            }
        }
        else
        {
            if (n & 1) k = (n - 1) / 2;
            else k = n / 2;
            if (!(k & 1) && !(n & 1))
            {
                for (int i = k; i <= n; i += 2) printf("%d ", i);
                for (int i = 2; i <= k - 2; i += 2) printf("%d ", i);
                for (int i = k + 3; i <= n - 1; i += 2) printf("%d ", i);
                for (int i = 1; i < k + 1; i += 2) printf("%d ", i);
                printf("%d\n", k + 1);
            }
            else if (!(k & 1) && (n & 1))
            {
                for (int i = k; i <= n - 1; i += 2) printf("%d ", i);
                for (int i = 2; i <= k - 2; i += 2) printf("%d ", i);
                for (int i = k + 3; i <= n - 2; i += 2) printf("%d ", i);
                for (int i = 1; i <= k + 1; i += 2) printf("%d ", i);
                printf("%d\n", n);
            }
            else if ((k & 1) && !(n & 1))
            {
                for (int i = k; i <= n - 1; i += 2) printf("%d ", i);
                for (int i = 1; i <= k - 2; i += 2) printf("%d ", i);
                for (int i = k + 3; i <= n; i += 2) printf("%d ", i);
                for (int i = 2; i < k + 1; i += 2) printf("%d ", i);
                printf("%d\n", k + 1);
            }
            else
            {
                for (int i = k; i <= n - 2; i += 2) printf("%d ", i);
                for (int i = 1; i <= k - 2; i += 2) printf("%d ", i);
                for (int i = k + 3; i <= n - 1; i += 2) printf("%d ", i);
                for (int i = 2; i <= k + 1; i += 2) printf("%d ", i);
                printf("%d\n", n);
            }

        }
    }
    return 0;
}
