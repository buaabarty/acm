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
class FallingCoconuts {
public:
    vector <string> harvest(vector <int> drops) {
        vector <string> res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int dropsARRAY[] = {8, 9, 10, 11, 12, 8, 12, 10};
        vector <int> drops( dropsARRAY, dropsARRAY+ARRSIZE(dropsARRAY) );
        string retrunValueARRAY[] = {"OOOOOOO", "---O---" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingCoconuts theObject;
        eq(0, theObject.harvest(drops),retrunValue);
    }
    {
        int dropsARRAY[] = {5, 20, 5, 20, 5, 6, 7};
        vector <int> drops( dropsARRAY, dropsARRAY+ARRSIZE(dropsARRAY) );
        string retrunValueARRAY[] = {"OOOOO-----------OO" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingCoconuts theObject;
        eq(1, theObject.harvest(drops),retrunValue);
    }
    {
        int dropsARRAY[] = {6, 8, 10, 7, 9, 8, 8, 8, 8, 8};
        vector <int> drops( dropsARRAY, dropsARRAY+ARRSIZE(dropsARRAY) );
        string retrunValueARRAY[] = {"OOOOOO", "-OOO--", "--O---" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingCoconuts theObject;
        eq(2, theObject.harvest(drops),retrunValue);
    }
    {
        int dropsARRAY[] = {0, 0, 0, 0};
        vector <int> drops( dropsARRAY, dropsARRAY+ARRSIZE(dropsARRAY) );
        string retrunValueARRAY[] = {"OOO", "-O-" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingCoconuts theObject;
        eq(3, theObject.harvest(drops),retrunValue);
    }
    {
        int dropsARRAY[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 
           5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        vector <int> drops( dropsARRAY, dropsARRAY+ARRSIZE(dropsARRAY) );
        string retrunValueARRAY[] = {"OOOOOOOOOOOO", "-OOOOOOOOOO-", "--OOOOOOOO--", "---OOOOOO---", "----OOOO----", "-----OO-----" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingCoconuts theObject;
        eq(4, theObject.harvest(drops),retrunValue);
    }
    return 0;
}
// END CUT HERE
