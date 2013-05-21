#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10000 + 10;
typedef long long LL;
inline LL sqr( int x )
{
    return ( LL )x * x;
}
struct graph
{
    int deg[ N ], n, m;
    void read()
    {
        scanf("%d%d", &n, &m);
        memset( deg, 0, sizeof(deg) );
        for ( int i = 1; i <= m; ++i )
        {
            int x, y;
            scanf( "%d%d", &x, &y );
            deg[ x ]++;
            deg[ y ]++;
        }
    }
    LL ans()
    {
        LL tot = 0;
        for ( int i = 1; i <= n; ++i )
        {
            tot += sqr( deg[ i ] );
        }
        return tot;
    }
}g;
int main()
{
    g.read();
    printf( "%lld\n", g.ans() );
    return 0;
}
