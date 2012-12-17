#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long a, b, c;
    cin >> a;
    long long x, y;
    for (x = a; x >= 1; --x)
        if ((a * a + 1) % x == 0) break;
    y = (a * a + 1) / x;
    b = a + x;
    c = a + y;
    printf("%d\n", b + c);
    return 0;
}
