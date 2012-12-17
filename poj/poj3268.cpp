#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 1010
using namespace std;
int map[MAX_N][MAX_N], d1[MAX_N], d2[MAX_N];
int n, m, x;
void init()
{
    scanf("%d%d%d", &n, &m, &x);
    memset(map, 0x7f, sizeof(map));
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = min(map[a][b], c);
    }
}
void dijk1(int v)
{
    vector
}
int doit()
{
    memset(d1, 0x7f, sizeof(d1));
    memset(d2, 0x7f, sizeof(d2));
    dijk1(x);
    dijk2(x);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (d1[i] + d2[i] < 0x7f)
            res = max(res, d1[i] + d2[i]);
    return res;
}
int main()
{
    init();
    cout << doit() << endl;
    return 0;
}
