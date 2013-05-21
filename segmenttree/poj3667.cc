#include <iostream>
#include <cstdio>
#include <cstring>
#define pl p<<1
#define pr p<<1|1
using namespace std;
const int maxn = 200000 + 9;
struct segment_tree {
    int lc[maxn], rc[maxn], mc[maxn];
    int g[2][maxn];
    void build(int p, int l, int r) {
        lc[p] = rc[p] = mc[p] = r - l + 1;
        g[0][p] = g[1][p] = 0;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(pl, l, mid);
        build(pr, mid+1, r);
    }
    void clean( int p, int c, int l, int r ) {
        if ( c == 1 ) {
            mc[p] = lc[p] = rc[p] = ( r - l + 1 );
        } else {
            mc[p] = lc[p] = rc[p] = 0;
        }
    }
    void push( int p, int l, int r ) {
        int mid = ( l + r ) >> 1;
        for ( int i = 0; i <= 1; ++i )
            if ( g[i][p] ) {
                g[i][pl] = g[i][pr] = 1; g[i][p] = g[1-i][p] = g[1-i][pl] = g[1-i][pr] = 0;
                clean( pl, i, l, mid );
                clean( pr, i, mid + 1, r );
                return ;
            }
    }
    void pop( int p, int l, int r ) {
        //cout << "POP" << endl;
        for (int i = 0; i <= 1; ++i)
            if ( g[i][pl] && g[i][pr] ) {
                g[i][p] = 1; g[1 - i][p] = g[i][pl] = g[i][pr] = 0;
                clean( p, i, l, r );
                return ;
            }
        g[0][p] = g[1][p] = 0;
        //cout << "PPPP     " << p << " " << l << " " << r << endl;
        //cout << "DATA M  " << mc[p] << " " << mc[pl] << " " << mc[pr] << endl;
        //cout << "DATA L  " << lc[p] << " " << lc[pl] << " " << lc[pr] << endl;
        //cout << "DATA R  " << rc[p] << " " << rc[pl] << " " << rc[pr] << endl;
        //cout << endl;
        int mid = ( l + r ) >> 1;
        mc[p] = max( max( mc[pl], mc[pr] ), rc[pl] + lc[pr] );
        if ( mc[pr] == r - mid ) rc[p] = mc[pr] + rc[pl];
        else rc[p] = rc[pr];
        if ( mc[pl] == mid - l + 1 ) lc[p] = mc[pl] + lc[pr];
        else lc[p] = lc[pl];
        //cout << "DATA M  " << mc[p] << " " << mc[pl] << " " << mc[pr] << endl;
        //cout << "DATA L  " << lc[p] << " " << lc[pl] << " " << lc[pr] << endl;
        //cout << "DATA R  " << rc[p] << " " << rc[pl] << " " << rc[pr] << endl;
        //cout << endl << endl;
    }
    void insert(int p, int l, int r, int a, int b, int c) {
        //cout << "INS  " << p << " " << l << " " << r << " " << a << " " << b << " " << c << endl;
        if (a == l && b == r) {
            g[c][p] = 1;
            g[1 - c][p] = 0;
            clean( p, c, l, r );
            //cout << "DATA    " << mc[p] << " " << mc[pl] << " " << mc[pr] << endl;
            return ;
        }
        push( p, l, r );
        int mid = (l + r) >> 1;
        if (b <= mid) insert(pl, l, mid, a, b, c);
        else if (a > mid) insert(pr, mid+1, r, a, b, c);
        else {
            insert(pl, l, mid, a, mid, c);
            insert(pr, mid+1, r, mid+1, b, c);
        }
        pop( p, l, r );
        //cout << "DATA    " << mc[p] << " " << mc[pl] << " " << mc[pr] << endl;
    }
    int query( int p, int l, int r, int len ) {
        //cout << "QUERY  " << p << " " << l << " " << r << " " << len << endl;
        //cout << "DATA M  " << mc[p] << " " << mc[pl] << " " << mc[pr] << endl;
        //cout << "DATA L  " << lc[p] << " " << lc[pl] << " " << lc[pr] << endl;
        //cout << "DATA R  " << rc[p] << " " << rc[pl] << " " << rc[pr] << endl;
        push( p, l, r );
        if ( mc[p] == len && r - l + 1 == len ) return l;
        if ( mc[p] < len ) return 0;
        int mid = (l + r)>>1;
        if ( mc[pl] >= len ) return query( pl, l, mid, len );
        else if ( rc[pl] + lc[pr] >= len ) {
            if ( rc[pl] ) return mid - rc[pl] + 1;
            else return mid + 1;
        } else if ( mc[pr] >= len ) return query( pr, mid + 1, r, len );
        else return 0;
    }
}sg;
int main() {
    int n, m;
    scanf( "%d%d", &n, &m );
    sg.build( 1, 1, n );
    while ( m-- ) {
        int a, x, y;
        scanf( "%d%d", &a, &x );
        if ( a == 1 ) {
            int loc = sg.query( 1, 1, n, x );
            printf( "%d\n", loc );
            if ( loc ) {
                sg.insert( 1, 1, n, loc, loc + x - 1, 0 );
            }
        } else {
            int y; scanf( "%d", &y );
            sg.insert( 1, 1, n, x, x + y - 1, 1 );
        }
    }
    return 0;
}
