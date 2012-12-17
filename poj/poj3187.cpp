#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
bool next(vector<int> &now)
{
    int cnt = now.size(), a = -1, b, t = INT_MAX;
    for (int i = 0; i + 1 < cnt; ++i)
        if (now[i] < now[i + 1]) a = i;
    if (a == -1)
    {
        return false;
    }
    for (int i = a + 1; i < cnt; ++i)
        if ((now[i] > now[a]) && (now[i] < t))
        {
            t = now[i];
            b = i;
        }
    swap(now[a], now[b]);
    for (int i = a + 1; a + cnt - i > i; ++i)
        swap(now[i], now[a + cnt - i]);
    return true;
}
int main()
{
    int n, s, num[100];
    while (~scanf("%d%d", &n, &s))
    {
        vector<int> data;
        for (int i = 1; i <= n; ++i) data.push_back(i);
        do
        {
            for (int i = 0; i < n; ++i) num[i] = data[i];
            for (int i = n - 1; i >= 1; --i)
                for (int j = 0; j < i; ++j)
                    num[j] = num[j] + num[j + 1];
            if (num[0] == s) break;
        } while (next(data));
        for (int i = 0; i + 1 < n; ++i)
            printf("%d ", data[i]);
        printf("%d\n", data[n - 1]);
    }
    return 0;
}
