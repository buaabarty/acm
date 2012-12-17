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
// END CUT HERE
bool vst[10][45010];
int step[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
struct pt
{
    int x, y;
    pt(int _x, int _y)
    {
        x = _x; y = _y;
    }
    pt(){}
}q[45010*10];
class KnightCircuit2 {
public:
    int maxSize(int w, int h) {
        if (w > h) swap(w, h);
        if (w >= 10) return w * h;
        memset(vst, 0, sizeof(vst));

        int l = 1, r = 1, tot = 1;
        q[1] = pt(1, 1);
        vst[1][1] = 1;
        while (l <= r) {
            pt now = q[l++];
            for (int k = 0; k < 8; ++k)
            {
                int dx = now.x + step[k][0];
                int dy = now.y + step[k][1];
                if (dx>=1&&dx<=w&&dy>=1&&dy<=h&&!vst[dx][dy])
                {
                    q[++r] = pt(dx, dy);
                    vst[dx][dy] = 1;
                    ++tot;
                }
            }
        }
        return tot;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        KnightCircuit2 theObject;
        eq(0, theObject.maxSize(1, 1),1);
    }
    {
        KnightCircuit2 theObject;
        eq(1, theObject.maxSize(4, 45000),1);
    }
    {
        KnightCircuit2 theObject;
        eq(2, theObject.maxSize(100, 100),10000);
    }
    return 0;
}
// END CUT HERE