#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); ++i)
        if ((a[i] >= 'A') && (a[i] <= 'Z')) a[i] = a[i] - 'A' + 'a';
    for (int i = 0; i < b.length(); ++i)
        if ((b[i] >= 'A') && (b[i] <= 'Z')) b[i] = b[i] - 'A' + 'a';
    if (a < b) puts("-1");
    else if (a == b) puts("0");
    else puts("1");
    return 0;
}
