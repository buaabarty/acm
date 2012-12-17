#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
int main()
{
    LL n, x, y;
    cin >> n >> x >> y;
    LL s = 0;
    if (n > y)
    {
        puts("-1");
        return 0;
    }
    for (LL i = 1; i < n; ++i) s ++;
    s += (y - n + 1) * (y - n + 1);
    if (s >= x)
    {
        for (LL i = 1; i < n; ++i) puts("1");
        cout << y - n + 1 << endl;
        return 0;
    }
    puts("-1");
    return 0;
}
