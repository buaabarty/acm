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
class ScotlandYard {
public:
    int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string taxiARRAY[] = {"NYN",
            "NNY",
            "NNN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NNN",
            "NNN",
            "NNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNN",
            "NNN",
            "NNN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(0, theObject.maxMoves(taxi, bus, metro),2);
    }
    {
        string taxiARRAY[] = {"NYY",
            "NNN",
            "NNN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NNN",
            "NNN",
            "NNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNN",
            "NNN",
            "NNN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(1, theObject.maxMoves(taxi, bus, metro),1);
    }
    {
        string taxiARRAY[] = {"NYYY",
            "YNYY",
            "YYNY",
            "YYYN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NNNN",
            "NNNN",
            "NNNN",
            "NNNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNNN",
            "NNNN",
            "NNNN",
            "NNNN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(2, theObject.maxMoves(taxi, bus, metro),-1);
    }
    {
        string taxiARRAY[] = {"NNY",
            "NNY",
            "NNN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NYN",
            "NNY",
            "NNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNN",
            "NNN",
            "YNN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(3, theObject.maxMoves(taxi, bus, metro),2);
    }
    {
        string taxiARRAY[] = {"NNN",
            "YNY",
            "NNN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NNN",
            "YNN",
            "YNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNN",
            "NNN",
            "YYN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(4, theObject.maxMoves(taxi, bus, metro),-1);
    }
    {
        string taxiARRAY[] = {"NNNNYNNNYY",
            "NNYNNYYYYY",
            "NNNNNNNNNN",
            "YYNNYYNNNY",
            "NNYNNNNNNN",
            "YNYNYNNNYN",
            "NNYNYNNNYN",
            "NNNNNNYNNN",
            "NNNNNNNNNN",
            "NNNNNNYNNN"};
        vector <string> taxi( taxiARRAY, taxiARRAY+ARRSIZE(taxiARRAY) );
        string busARRAY[] = {"NNYNNNYNNY",
            "YNYNNYYNYY",
            "NNNNNNNNNN",
            "YNYNNYNYNY",
            "NNYNNNNNYN",
            "YNYNYNYNYN",
            "NNYNNNNNNY",
            "YNYNNNNNNN",
            "NNNNNNNNNN",
            "NNYNYNNNNN"};
        vector <string> bus( busARRAY, busARRAY+ARRSIZE(busARRAY) );
        string metroARRAY[] = {"NNNNNNNYNN",
            "YNYNNNNNYN",
            "NNNNNNNNNN",
            "NYNNYNNNYY",
            "NNYNNNNNNN",
            "YNYNNNNNYY",
            "NNNNYNNNYN",
            "NNYNNNYNNN",
            "NNNNNNNNNY",
            "NNYNYNNNNN"};
        vector <string> metro( metroARRAY, metroARRAY+ARRSIZE(metroARRAY) );
        ScotlandYard theObject;
        eq(5, theObject.maxMoves(taxi, bus, metro),21);
    }
    return 0;
}
// END CUT HERE
