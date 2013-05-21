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
class WolfInZooDivOne {
public:
    int count(int N, vector <string> L, vector <string> R) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string LARRAY[] = {"0"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"4"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(0, theObject.count(5, L, R),16);
    }
    {
        string LARRAY[] = {"0 1"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"2 4"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(1, theObject.count(5, L, R),21);
    }
    {
        string LARRAY[] = {"0 4 2 7"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"3 9 5 9"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(2, theObject.count(10, L, R),225);
    }
    {
        string LARRAY[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(3, theObject.count(100, L, R),6419882);
    }
    return 0;
}
// END CUT HERE
