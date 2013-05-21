#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10010 + 10;

int func( int x )
{
    int cnt = 0, ans = x;
    for ( int i = 2; i * i <= x; ++i )
        if ( x % i == 0 )
        {
            while ( x % i == 0 )
            {
                x /= i;
            }
            ans = ans * ( i - 1 ) / i;
        }
    if ( x > 1 )
    {
        ans = ans * ( x - 1 ) / x;
    }
    return ans;
}

int main()
{
    int n;
    while ( scanf( "%d", &n ) == 1 )
    {
        printf( "%d\n", func(n) );
    }
    return 0;
}
