#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string a, b;
int ord(char x)
{
    switch (x){
        case 'S':return 2;break;
        case 'P':return 1;break;
        case 'R':return 0;break;
        default :return -1;
    }
}
int res(char x, char y)
{
    return (ord(x) - ord(y) + 3) % 3;
}
int main()
{
    int n, cnt[3];
    while (cin >> a >> b)
    {
        if (a[0] == 'E') break;
        n = a.length();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i)
            ++cnt[res(a[i], b[i])];
        cout << "P1: " << cnt[1] << endl;
        cout << "P2: " << cnt[2] << endl;
    }
    return 0;
}
