#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int mat[501][501];
int dp[501][501][2][11];

const int module = 1000000007;

int add11( int a, int b ) {
    a += b;
    while ( a >= 11 ) a -= 11;
    while ( a < 0 ) a += 11;
    return a;
}

void add_eq( int &a, int &b ) {
    a += b;
    if ( a >= module ) a -= module;
}

void solve(int ri) {
    int r, c; cin >> r >> c;
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            scanf( "%1d", &mat[i][j] );
        }
    }
    int ans = 0;
    for ( int i = 0; i < r; ++i ) {
        for ( int j = 0; j < c; ++j ) {
            for ( int step = 0; step < 2; ++step ) {
                for ( int diff = 0; diff <= 10; ++diff ) {
                    dp[i][j][step][diff] = 0;
                }
            }
            dp[i][j][0][ mat[i][j] % 11 ] = 1;
            for ( int step = 0; step < 2; ++step ) {
                for ( int diff = 0; diff <= 10; ++diff ) {
                    if ( i > 0 ) {
                        add_eq(dp[i][j][step][diff],
                               dp[i-1][j][step^1][ add11(diff, step ? mat[i][j] : -mat[i][j]) ]);
                    }
                    if ( j > 0 ) {
                        add_eq(dp[i][j][step][diff],
                               dp[i][j-1][step^1][ add11(diff, step ? mat[i][j] : -mat[i][j]) ]);
                    }
                    if ( diff == 0 ) {
                        add_eq( ans, dp[i][j][step][diff] );
                    }
                }
            }
        }
    }
    printf("Case %d: ", ri);
    cout << ans << endl;
}

int main() {
    int re; cin >> re;
    for ( int ri = 1; ri <= re; ++ri ) solve(ri);
}
