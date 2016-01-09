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
class TreeAndPathLength3 {
public:
    vector <int> construct(int s) {
        for (int i = 1; i <= 500; ++i) {
            for (int j = 1; j <= i; ++j) {
                int rem = s - i * j;
                if (rem < 0 || rem + i + j + 2 > 500) {
                    continue;
                }
                vector<int> res;
                res.push_back(0);
                res.push_back(1);
                int cnt = 2;
                for (int x = 1; x <= i - 1; ++x) {
                    res.push_back(0);
                    res.push_back(cnt++);
                }
                for (int y = 1; y <= j - 1; ++y) {
                    res.push_back(1);
                    res.push_back(cnt++);
                }
                res.push_back(1);
                res.push_back(cnt);
                res.push_back(cnt++);
                res.push_back(cnt);
                while (rem--) {
                    res.push_back(cnt++);
                    res.push_back(cnt);
                }
                return res;
            }
        }
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int retrunValueARRAY[] = {0, 1, 1, 2, 2, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeAndPathLength3 theObject;
        eq(0, theObject.construct(1),retrunValue);
    }
    {
        int retrunValueARRAY[] = {0, 1, 1, 2, 2, 3, 3, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeAndPathLength3 theObject;
        eq(1, theObject.construct(2),retrunValue);
    }
    {
        int retrunValueARRAY[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeAndPathLength3 theObject;
        eq(2, theObject.construct(6),retrunValue);
    }
    {
        int retrunValueARRAY[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TreeAndPathLength3 theObject;
        eq(3, theObject.construct(8000),retrunValue);
    }
    return 0;
}
// END CUT HERE
