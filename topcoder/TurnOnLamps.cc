// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE
class TurnOnLamps {
public:
    struct edge {
        int v, st, im, next;
    } e[1000];
    int p[1000], eid;
    void init() {
        memset(p, -1, sizeof(p));
        eid = 0;
    }
    void insert(int x, int y, int st, int im) {
        e[eid].v = y;
        e[eid].st = st;
        e[eid].im = im;
        e[eid].next = p[x];
        p[x] = eid++;
    }
    void insert2(int x, int y, int st, int im) {
        insert(x, y, st, im);
        insert(y, x, st, im);
    }
    int n, dp[100], up[100];
    bool vst[100];
    void dfs(int v, int fim, int im) {
        vst[v] = 1;
        int cnt = 0, sum = 0;
        for (int i = p[v]; ~i; i = e[i].next)
            if (!vst[e[i].v]) {
                dfs(e[i].v, e[i].im && e[i].st, e[i].im);
                sum += dp[e[i].v];
                cnt += up[e[i].v];
            }
        int gao = cnt / 2;
        sum += gao;
        cnt %= 2;
        if (fim) {
            if (cnt) ++sum;
            dp[v] = sum;
            up[v] = 0;
        } else {
            if (cnt || im) up[v] = 1;
            else up[v] = 0;
            dp[v] = sum;
        }

    }
    int minimize(vector <int> roads, string initState, string isImportant) {
        n = initState.length() + 1;
        init();
        for (int i = 0; i < n - 1; ++i) insert2(i + 1, roads[i], initState[i] == '1', isImportant[i] == '1');
        memset(vst, 0, sizeof(vst));
        dfs(0, 0, 0);
        if (up[0]) dp[0]++;
        return dp[0];
    }

};
// BEGIN CUT HERE
int main() {
    {
        int roadsARRAY[] = {0,0,1,1};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(0, theObject.minimize(roads, "0001", "0111"),1);
    }
    {
        int roadsARRAY[] = {0,0,1,1};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(1, theObject.minimize(roads, "0000", "0111"),2);
    }
    {
        int roadsARRAY[] = {0,0,1,1,4,4};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(2, theObject.minimize(roads, "000100", "111111"),2);
    }
    {
        int roadsARRAY[] = {0,0,1,1,4,4};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(3, theObject.minimize(roads, "100100", "011101"),2);
    }
    {
        int roadsARRAY[] = {0,0,2,2,3,1,6,3,1};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(4, theObject.minimize(roads, "010001110", "000110100"),1);
    }
    {
        int roadsARRAY[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
        vector <int> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        TurnOnLamps theObject;
        eq(5, theObject.minimize(roads, "0000000000010000000000000010000010100000000000000", "1010111111111011011111000110111111111111111110111"),14);
    }
    return 0;
}
// END CUT HERE
