#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 32768
using namespace std;
int t, n, num[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> num[i];
        sort(num + 1, num + n + 1);
        int sum = 0;
        for (int i = n - 2; i >= 1; i -= 3) sum += num[i];
        cout << sum << endl;
    }
    return 0;
}
