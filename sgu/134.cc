#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define loopv(v) for (int i = 0, sz = v.size(); i < sz; ++i)
using namespace std;

const int N = 16000 + 11;

template <typename T> void checkmax(T &a, T b) { if (b > a) a = b; }

struct TreeDp {
    int n, f[N], ans;
    vector<int> e[N];
    bool vst[N];
    vector<int> loc;
    void init() {
        scanf( "%d", &n );
        for ( int i = 1; i <= n; ++i ) e[i].clear();
        for ( int i = 1; i < n; ++i ) {
            int x, y;
            scanf( "%d%d", &x, &y );
            e[x].pb(y); e[y].pb(x);
        }
        memset( vst, 0, sizeof(vst) );
        ans = n + 1;
    }
    void dfs( int v ) {
        int now = 0;
        f[v] = 1;
        vst[v] = 1;
        loopv(e[v]) {
            if (!vst[e[v][i]]) {
                dfs( e[v][i] );
                checkmax( now, f[e[v][i]] );
                f[v] += f[e[v][i]];
            }
        }
        checkmax( now, n - f[v] );
        if ( now < ans ) {
            ans = now;
            loc.clear();
            loc.pb(v);
        } else if ( now == ans ) {
            loc.pb(v);
        }
    }
}t;

int main() {
    t.init();
    t.dfs(1);
    sort( t.loc.begin(), t.loc.end() );
    printf( "%d %d\n", t.ans, t.loc.size() );
    loopv( t.loc ) {
        printf( "%d%c", t.loc[i], " \n"[i==t.loc.size()-1] );
    }
    return 0;
}
