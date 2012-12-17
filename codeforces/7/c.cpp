#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL ext_gcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        LL g = ext_gcd(b, a % b, x, y);
        LL t = x;
        x = y;
        y = t - (a / b) * y;
        return g;
    }
}
LL a, b, c, x, y;
int main()
{
    cin >> a >> b >> c;
    c = -c;
    LL g = ext_gcd(a, b, x, y);
    if ((c % g) != 0) cout << -1 << endl;
    else
    {
        LL k = c / g;
        x *= k;
        y *= k;
        cout << x << " " << y << endl;
    }
    return 0;
}
