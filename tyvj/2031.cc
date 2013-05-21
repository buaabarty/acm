#include <iostream>
#include <cstdio>
#include <cstring>
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;

void gao( int n, int k ) {
    int last[ n*n/4 + 10 ], mask[ n ][ n ], tot = 0;
    clr( mask );
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( !mask[i][j] ) {
                mask[i][j] = mask[ n-i+1 ][j] = mask[i][ n-j+1 ] = mask[ n-i+1 ][ n-j+1 ] = ++tot;
            }
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            printf( "%d%c", mask[i][j], " \n"[ j==n ] );
}

int main() {
    int n, k;
    cin >> n >> k;
    gao( n, k );
    return 0;
}
