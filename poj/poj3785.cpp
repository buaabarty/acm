#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
bool in_a_row(string str)
{
    for (int i = 1, l = str.length(); i < l; ++i)
        if (str[i] < str[i - 1]) return false;
    return true;
}
int t, ca;
string str;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> ca >> str;
        next_permutation(str.begin(), str.end());
        if (in_a_row(str)) cout << ca << " BIGGEST" << endl;
        else cout << ca << " " << str << endl;
    }
    return 0;
}
