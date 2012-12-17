#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        if (str[0] == '#') break;
        if (next_permutation(str.begin(), str.end())) cout << str << endl;
        else cout << "No Successor" << endl;
    }
    return 0;
}
