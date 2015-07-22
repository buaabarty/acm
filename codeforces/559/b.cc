#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 200000 + 9;
int a[N], b[N];
map<string, int> d;
string sa, sb;
int sz = 0;
bool diff(int la, int ra, int lb, int rb, int dd) {
    if (la == ra) return a[la] == b[lb];
    return diff(la, la + dd - 1, lb, lb + dd - 1, dd >> 1) && diff(la + dd, ra, lb + dd, rb, dd >> 1)
        || diff(la, la + dd - 1, lb + dd, rb, dd >> 1) && diff(la + dd, ra, lb, lb + dd - 1, dd >> 1);
}
int getid(string s) {
    auto i = d.find(s);
    if (i != d.end()) {
        return i -> second;
    } else {
        d[s] = sz;
        return sz++;
    }
}
int main() {
    cin >> sa >> sb;
    if (sa.length() % 2 != 0 || sa.length() != sb.length()) {
        cout << "NO" << endl;
        return 0;
    }
    int n = sa.length(), sp;
    sp = n;
    while (sp % 2 == 0) {
        sp >>= 1;
    }
    for (int i = 0; i < n / sp; ++i)
        a[i] = getid(sa.substr(i * sp, sp));
    for (int i = 0; i < n / sp; ++i)
        b[i] = getid(sb.substr(i * sp, sp));
    puts(diff(0, n/sp - 1, 0, n/sp - 1, n / sp / 2) ? "YES" : "NO");
    return 0;
}
