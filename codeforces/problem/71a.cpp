#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t; scanf("%d", &t);
    string s;
    while (t--)
    {
        cin >> s;
        if (s.length() > 10) printf("%c%d%c\n", s[0], s.length() - 2, s[s.length() - 1]);
        else cout << s << endl;
    }
    return 0;
}
