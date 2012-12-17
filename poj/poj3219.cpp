#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        cout << ((n & k) == k) << endl;
    }
    return 0;
}
