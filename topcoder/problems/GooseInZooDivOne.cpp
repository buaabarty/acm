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
#include <cctype>
#include <cstring>
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
typedef long long LL;
const LL module = 1000000007;
LL vst[60][60];
LL dat[60][60];
LL c[2510][2510];
class GooseInZooDivOne {
public:
    LL n, m;
    LL cnt, d;
    LL iabs(LL x) {
        return (x > 0) ? x : -x;
    }
    void go(LL x, LL y) {
        ++cnt;
        vst[x][y] = 1;
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= m; ++j)
                if (!vst[i][j] && dat[i][j] && iabs(x-i)+iabs(y-j)<=d) go(i, j);
    }
    LL pow(LL x, LL y) {
        LL s = 1;
        while (y) {
            if (y&1) s = (s * x) % module;
            x = (x*x)%module;
            y >>= 1;
        }
        return s;
    }
    int count(vector <string> field, int dist) {
        d = dist;
        n = field.size();
        m = field[0].length();
        memset(vst, 0, sizeof(vst));
        memset(dat, 0, sizeof(dat));
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= m; ++j)
                dat[i][j] = (field[i-1][j-1] == 'v');
        }
        LL a = 0, b = 0;
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= m; ++j)
                if (!vst[i][j] && dat[i][j]) {
                    cnt = 0;
                    go(i, j);
                    if (cnt&1) ++a;
                    else ++b;
                }
        }
        c[0][0] = 1;
        for (LL i = 1; i <= 2500; ++i) {
            c[i][0] = 1;
            for (LL j = 1; j <= i; ++j) {
                c[i][j] = c[i-1][j] + c[i-1][j-1];
                if (c[i][j] >= module) c[i][j] -= module;
            }
        }
        LL ans = pow(2, b), p = 0;
        for (LL i = 0; i <= a; i += 2) {
            p = (p + c[a][i]) % module;
        }
        ans = (ans * p) % module;
        ans = (ans + module - 1) % module;
        return ans;
    }
};

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string fieldARRAY[] = {"vvv"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivOne theObject;
        eq(0, theObject.count(field, 0),3);
    }
    {
        string fieldARRAY[] = {"."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivOne theObject;
        eq(1, theObject.count(field, 100),0);
    }
    {
        string fieldARRAY[] = {"vvv"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivOne theObject;
        eq(2, theObject.count(field, 1),0);
    }
    {
        string fieldARRAY[] = {"v.v..................v............................"
           ,".v......v..................v.....................v"
           ,"..v.....v....v.........v...............v......v..."
           ,".........vvv...vv.v.........v.v..................v"
           ,".....v..........v......v..v...v.......v..........."
           ,"...................vv...............v.v..v.v..v..."
           ,".v.vv.................v..............v............"
           ,"..vv.......v...vv.v............vv.....v.....v....."
           ,"....v..........v....v........v.......v.v.v........"
           ,".v.......v.............v.v..........vv......v....."
           ,"....v.v.......v........v.....v.................v.."
           ,"....v..v..v.v..............v.v.v....v..........v.."
           ,"..........v...v...................v..............v"
           ,"..v........v..........................v....v..v..."
           ,"....................v..v.........vv........v......"
           ,"..v......v...............................v.v......"
           ,"..v.v..............v........v...............vv.vv."
           ,"...vv......v...............v.v..............v....."
           ,"............................v..v.................v"
           ,".v.............v.......v.........................."
           ,"......v...v........................v.............."
           ,".........v.....v..............vv.................."
           ,"................v..v..v.........v....v.......v...."
           ,"........v.....v.............v......v.v............"
           ,"...........v....................v.v....v.v.v...v.."
           ,"...........v......................v...v..........."
           ,"..........vv...........v.v.....................v.."
           ,".....................v......v............v...v...."
           ,".....vv..........................vv.v.....v.v....."
           ,".vv.......v...............v.......v..v.....v......"
           ,"............v................v..........v....v...."
           ,"................vv...v............................"
           ,"................v...........v........v...v....v..."
           ,"..v...v...v.............v...v........v....v..v...."
           ,"......v..v.......v........v..v....vv.............."
           ,"...........v..........v........v.v................"
           ,"v.v......v................v....................v.."
           ,".v........v................................v......"
           ,"............................v...v.......v........."
           ,"........................vv.v..............v...vv.."
           ,".......................vv........v.............v.."
           ,"...v.............v.........................v......"
           ,"....v......vv...........................v........."
           ,"....vv....v................v...vv..............v.."
           ,".................................................."
           ,"vv........v...v..v.....v..v..................v...."
           ,".........v..............v.vv.v.............v......"
           ,".......v.....v......v...............v............."
           ,"..v..................v................v....v......"
           ,".....v.....v.....................v.v......v......."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivOne theObject;
        eq(3, theObject.count(field, 3),898961330);
    }
    return 0;
}
// END CUT HERE
