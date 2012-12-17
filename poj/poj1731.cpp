#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string str;
int n;
bool legal(int x)
{
    return (x >= 0) && (x < n);
}
string next(string a)
{
    int i, j, mk = 1024, k;
    for (i = n - 2; i >= 0; --i)
        if (a[i] < a[i + 1]) break;
    for (k = n - 1; k > i; --k)
        if (a[k] > a[i]) break;
    if (!legal(i) || !legal(k)) return "";
    swap(a[i], a[k]);
    string temp;
    int tl = 0;
    temp.assign(n, ' ');
    for (j = 0; j <= i; ++j) temp[tl++] = a[j];
    for (j = n - 1; j > i; --j) temp[tl++] = a[j];
    return temp;
}
int main()
{
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (str[i] > str[j]) swap(str[i], str[j]);
    cout << str << endl;
    while (1)
    {
        str = next(str);
        if (str == "") break;
        cout << str << endl;
    }
    return 0;
}
