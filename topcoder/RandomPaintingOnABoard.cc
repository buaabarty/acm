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
class RandomPaintingOnABoard {
public:
    double expectedSteps(vector <string> prob) {
        double res;
        return res;
    }

};
// BEGIN CUT HERE
int main() {
    {
        string probARRAY[] = {"10",
            "01"};
        vector <string> prob( probARRAY, probARRAY+ARRSIZE(probARRAY) );
        RandomPaintingOnABoard theObject;
        eq(0, theObject.expectedSteps(prob),3.0);
    }
    {
        string probARRAY[] = {"11",
            "11"};
        vector <string> prob( probARRAY, probARRAY+ARRSIZE(probARRAY) );
        RandomPaintingOnABoard theObject;
        eq(1, theObject.expectedSteps(prob),3.6666666666666665);
    }
    {
        string probARRAY[] = {"11",
            "12"};
        vector <string> prob( probARRAY, probARRAY+ARRSIZE(probARRAY) );
        RandomPaintingOnABoard theObject;
        eq(2, theObject.expectedSteps(prob),3.9166666666666665);
    }
    {
        string probARRAY[] = {"0976",
            "1701",
            "7119"};
        vector <string> prob( probARRAY, probARRAY+ARRSIZE(probARRAY) );
        RandomPaintingOnABoard theObject;
        eq(3, theObject.expectedSteps(prob),11.214334077031307);
    }
    {
        string probARRAY[] = {"000000000000001000000",
            "888999988889890999988",
            "988889988899980889999",
            "889898998889980999898",
            "988889999989880899999",
            "998888998988990989998",
            "998988999898990889899"};
        vector <string> prob( probARRAY, probARRAY+ARRSIZE(probARRAY) );
        RandomPaintingOnABoard theObject;
        eq(4, theObject.expectedSteps(prob),1028.7662876159634);
    }
    return 0;
}
// END CUT HERE
