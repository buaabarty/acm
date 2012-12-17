#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define N 100010
using namespace std;
int last[N], n, x, y;
set<int> hash;
int main()
{
    scanf("%d", &n);
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x, &y);
        hash.clear();
        for (int j = 1; j * j <= x; ++j)
            if (!(x % j))
            {
                int a = j, b = x / j;
                if (last[a] < i - y) hash.insert(a);
                if (last[b] < i - y) hash.insert(b);
                last[a] = last[b] = i;
            }
        printf("%d\n", hash.size());
    }
    return 0;
}
