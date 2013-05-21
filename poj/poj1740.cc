#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n, cnt;
    int num[200];
    while ( scanf( "%d", &n ), n ) {
        cnt = 0;
        for ( int i = 1; i <= n; ++i ) {
            scanf( "%d", &num[cnt + 1] );
            if ( num[cnt + 1] ) ++cnt;
        }
        n = cnt;
        sort( num + 1, num + n + 1 );
        if (n % 2) puts("1");
        else {
            bool flag = 0;
            for (int i = 1; i < n; i += 2)
                if ( num[i] != num[i + 1] ) {
                    flag = 1; break;
                }
            printf( "%d\n", flag );
        }
    }
    return 0;
}
