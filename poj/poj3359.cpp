#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(string str)
{
    int res = 1000000000;
    for (int i = 0, l = str.length(); i < l - 1; ++i)
        res = min(res, iabs(str[i] - str[i + 1]));
    return res;
}
string str, now, res;
int d;
int main()
{
    while (cin >> str)
    {
        now = str;
        res = now;
        d = dist(res);
        for (int i = 0; i < 10; ++i)
        {
            prev_permutation(now.begin(), now.end());
            int x = dist(now);
            if (x >= d)
            {
                d = x;
                res = now;
            }
        }
        now = str;
        for (int i = 0; i < 10; ++i)
        {
            next_permutation(now.begin(), now.end());
            int x = dist(now);
            if (x > d)
            {
                d = x;
                res = now;
            }
        }
        cout << res << d << endl;
    }
    return 0;
}
