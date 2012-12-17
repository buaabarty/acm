#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sum(int x, int m)
{
    int s = 0;
    while (x > 0)
    {
        s += x % m;
        x /= m;
    }
    return s;
}
bool legal(int x)
{
    return ((sum(x, 16) == sum(x, 12)) && (sum(x, 12) == sum(x, 10)));
}
int main()
{
    for (int i = 2992; i <= 9999; ++i)
        if (legal(i)) printf("%d\n", i);
    return 0;
}
