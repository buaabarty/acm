#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string calc(string mid, string first)
{
    int i = 0, len = mid.length();
    if (len == 1) return mid;
    if (len == 0) return "";
    for (; i < len; ++i)
        if (mid[i] == first[0]) break;
    return calc(mid.substr(0, i), first.substr(1, i))
         + calc(mid.substr(i + 1, len - i - 1), first.substr(i + 1, len - i - 1))
         + first.substr(0, 1);
}
int main()
{
    string a, b;
    while (cin >> a >> b)
        cout << calc(b, a) << endl;
    return 0;
}
