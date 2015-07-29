#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
string gao(string s) {
    if (s.length() % 2) return s;
    string left = gao(s.substr(0, s.length() / 2));
    string right = gao(s.substr(s.length() / 2, s.length() / 2));
    if (left > right) swap(left, right);
    return left + right;
}
string sa, sb;
int main() {
    cin >> sa >> sb;
    puts(gao(sa) == gao(sb) ? "YES" : "NO");
    return 0;
}
