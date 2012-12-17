#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, x, y;
int main()
{
    cin >> n >> x >> y;
    n /= 2;
    if (((x == n) && (y == n)) || ((x == n + 1) && (y == n + 1)) || ((x == n) && (y == n + 1)) || ((x == n + 1) && (y == n))) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
