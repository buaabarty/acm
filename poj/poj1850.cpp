#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long c(int n, int m)
{
    long long res = 1, j = 2;
    for (int i = n; i >= n - m + 1; --i)
    {
        res *= i;
        while (res % j == 0 && j <= m) res /= j++;
    }
    return res;
}
int main()
{
    string str;
    int x, y;
    while (cin >> str)
    {
        bool codified = true;
        long long res = 0;
        int len = str.length();
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (str[i] >= str[j])
                {
                    codified = false;
                    break;
                }
        if (!codified)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i < len; ++i)
            res += c(26, i);
        int m = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = m; j < str[i] - 'a'; j++)
                res += c(26 - j - 1, len - i - 1);
            m = str[i] - 'a' + 1;
        }
        cout << res + 1 << endl;
    }
    return 0;
}
