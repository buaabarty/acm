#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while ( scanf( "%d", &n ) == 1 )
    {
        printf( "%d\n", (n-1)/3*2+(n-1)%3 );
    }
    return 0;
}
