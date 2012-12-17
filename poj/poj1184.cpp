#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
int dist[1000000];
int p10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int calc(int x, int s)
{
    int ss = 0;
    for (int i = 5; i >= 0; --i)
    {
        ss += iabs((s % 10) - (x % 10));
        x /= 10;
        s /= 10;
    }
    return ss;
}
int swap(int a, int l, int r)
{
    int x = (a / p10[l - 1]) % 10;
    int y = (a / p10[r - 1]) % 10;
    printf("%d %d %d %d %d\n", a, l, r, x, y);
    a += x * (p10[r - 1] - p10[l - 1]) + y * (p10[l - 1] - p10[r - 1]);
    printf("%d\n", a);
    return a;
}
int d[10000000], ia, ib;
int main()
{
    cin >> ia >> ib;
    for (int i = 0; i < 1000000; ++i)
        dist[i] = calc(i, ib);
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[ia * 10 + 1] = 0;
    q.push(ia * 10 + 1);
    while (!q.empty())
    {
        int x = q.front();
        int nowd = d[x];
        int a = x / 10, b = x % 10;
        printf("%d %d\n", a, b);
        q.pop();
        if (b != 1)
        {
            int temp = swap(a, 1, b);
            if (d[temp * 10 + b] == -1)
            {
                d[temp * 10 + b] = nowd + 1;
                q.push(temp * 10 + b);
            }
            if (d[a * 10 + b - 1] == -1)
            {
                d[a * 10 + b - 1] = nowd + 1;
                q.push(a * 10 + b);
            }
        }
        if (b != 6)
        {
            int temp = swap(a, 6, b);
            if (d[temp * 10 + b] == -1)
            {
                d[temp * 10 + b] = nowd + 1;
                q.push(temp * 10 + b);
            }
            if (d[a * 10 + b + 1] == -1)
            {
                d[a * 10 + b + 1] = nowd + 1;
                q.push(a * 10 + b + 1);
            }
        }
    }
    int res = INT_MAX;
    for (int i = 1; i < 10000000; ++i)
        if (d[i] != -1) res = min(res, d[i] + dist[i / 10]);
    for (int i = 1; i < 10000000; ++i)
        if (d[i] != -1)
        {
            if (d[i] + dist[i / 10] == res)
                printf("%d %d %d\n", i, d[i], dist[i / 10]);
        }
    printf("%d\n", res);
    return 0;
}
