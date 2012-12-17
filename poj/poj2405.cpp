#include <cstdio>
#include <iostream>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main()
{
    int d, v;
    while (scanf("%d%d", &d, &v), d + v)
    {
        printf("%.3f\n", pow((double)d * d * d - 6.0 * v / PI, 1 / 3.0));
    }
    return 0;
}
