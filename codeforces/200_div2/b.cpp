#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
double x, sum;
int main()
{
    cin  >> n;
    sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        sum += x;
    }
    sum /= (double)n;
    cout << sum << endl;
    return 0;
}
