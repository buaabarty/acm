#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a, b, c;
int rank(char c)
{
    switch (c)
    {
        case '6': return 1; break;
        case '7': return 2; break;
        case '8': return 3; break;
        case '9': return 4; break;
        case 'T': return 5; break;
        case 'J': return 6; break;
        case 'Q': return 7; break;
        case 'K': return 8; break;
        case 'A': return 9; break;
    }
}
int main()
{
    while (cin >> a >> b >> c)
    {
        bool res = false;
        if ((a[0] == b[1]) && (c[1] != a[0])) res = true;
        else if ((b[1] == c[1]) && (rank(b[0]) > rank(c[0]))) res = true;
        if (res) puts("YES");
        else puts("NO");
    }
    return 0;
}
