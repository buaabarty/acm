#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX_N 100000
using namespace std;
int a, ca, l = 0;
int cnt[MAX_N];
int main()
{
    memset(cnt, 0, sizeof(cnt));
    for (int ca = 0; ca < 10; ++ca)
    {
        cin >> a;
        for (int i = 2; i < sqrt(a) + 1; ++i)
            if (a % i == 0)
            {
                int x = i, y = 0;
                while (a % i == 0)
                {
                    y++; a /= i;
                }
                cnt[x] += y;
            }
        if (a != 1) cnt[a]++;
    }
    long long res = 1;
    for (int i = 2; i <= 10000; ++i)
    {
        res *= (cnt[i] + 1);
        res %= 10;
    }
    cout << res << endl;
    return 0;
}
