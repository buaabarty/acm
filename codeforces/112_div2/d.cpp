#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define N 100010
using namespace std;
int n, last[N];
set<int> hash;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        hash.clear();
        for(int j = 1; j * j <= x; j++)
        {
            if(x % j == 0)
            {
                int r1 = j;
                int r2 = x / j;
                if(last[r1] < i - y)   hash.insert(r1);
                if(last[r2] < i - y)   hash.insert(r2);
                last[r1] = last[r2] = i;
            }
        }
        printf("%d\n", hash.size());
    }
    return 0;
}
