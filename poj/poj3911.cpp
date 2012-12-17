#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
__int64 n, c, t;
__int64 f(__int64 x)
{
    return x * (c - x * n);
}
int main()
{
    while (cin >> n >> c)
    {
        if (n == 0) cout << 0 << endl;
        else{
            t = c / (2 * n);
            if (f(t - 1) >= f(t)) t = t - 1;
            else if (f(t + 1) > f(t)) t = t + 1;
            cout << t << endl;
        }
    }
    return 0;
}
