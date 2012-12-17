#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
string numstr(int x)
{
    string temp = "";
    if (x >= 10)
    {
        temp = "  ";
        temp[0] = x / 10 + '0';
        temp[1] = (x % 10) + '0';
    }
    else
    {
        temp = " ";
        temp[0] = x + '0';
    }

    return temp;
}
string res(int deep)
{
    if (deep == 0) return "((A0|B0)|(A0|B0))";
    string temp = numstr(deep);
    return "((A" + temp + "|B" + temp + ")|(" + res(deep - 1) + "|((A" + temp + "|A" + temp + ")|(B" + temp + "|B" + temp + "))))";
}
int main()
{
    int n;
    cin >> n;
    cout << res(n - 1) << endl;
    return 0;
}
