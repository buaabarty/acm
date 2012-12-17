#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int s, ns = 0, i = 1;
    cin >> s;
    while ((ns < s) || ((ns - s) % 2))
    {
        ns += (i++);
    }
    cout << i - 1 << endl;
    return 0;
}
