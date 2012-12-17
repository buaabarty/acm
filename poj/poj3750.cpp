#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#define N 128
using namespace std;
int n, w, s;
string str[N];
bool use[N];
int go(int i)
{
    if (i < n) return i + 1;
    else return 1;
}
int next(int i)
{
    i = go(i);
    while (use[i]) i = go(i);
    return i;
}
int main()
{
    while (~scanf("%d", &n))
    {
        memset(use, false, sizeof(use));
        for (int i = 1; i <= n; ++i)
            cin >> str[i];
        scanf("%d,%d", &w, &s);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < s; ++j) w = next(w);
            cout << str[w] << endl;
            use[w] = true;
            if (i == n) break;
            w = next(w);
        }
    }
    return 0;
}
