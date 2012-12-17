#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1LL) / a) * ((m + a - 1LL) / a) << endl;
    return 0;
}
