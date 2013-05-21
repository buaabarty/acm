#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int f[50], s[50];
    f[1] = f[2] = 1;
    for ( int i = 3; i < 41; ++i )
        f[ i ] = f[ i-1 ] + f[ i-2 ];
    s[1] = 1;
    for ( int i = 2; i < 41; ++i )
        s[ i ] = s[ i-1 ] + f[ i ];
    while ( scanf( "%d", &n ) == 1 )
    {
        printf( "%d\n", s[n] );
    }
    return 0;
}
