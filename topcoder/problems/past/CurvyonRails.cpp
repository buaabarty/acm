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
class CurvyonRails {
public:
    int getmin(vector <string> field) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string fieldARRAY[] = {".."
           ,".."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(0, theObject.getmin(field),0);
    }
    {
        string fieldARRAY[] = {"wCCww"
           ,"wCC.."
           ,"..w.."
           ,"....w"
           ,"ww..w"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(1, theObject.getmin(field),0);
    }
    {
        string fieldARRAY[] = {"C.w"
           ,"..."
           ,".C."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(2, theObject.getmin(field),1);
    }
    {
        string fieldARRAY[] = {"."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(3, theObject.getmin(field),-1);
    }
    {
        string fieldARRAY[] = {"w"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(4, theObject.getmin(field),0);
    }
    {
        string fieldARRAY[] = {"CC..CCCw.CwC..CC.w.C",
            "C.CCCwCCC.w.w..C.w..",
            "wwww...CC.wC.Cw.CC..",
            "CC..CC.w..w.C..CCCC.",
            "CC.CCC..CwwCCC.wCC..",
            "w.C..wwCC.CC.wwwCC..",
            ".CC.CC..CCC..CC.CC.C",
            "Cw....C.C.CCC...CC..",
            "CC.C..Cww.C.CwwwC..w",
            "wCCww..C...CCCCCCC.w",
            "C.CCw.CC.ww...C.CCww",
            "C.C.C.CCwCC..wCCw.Cw",
            "CCC.C...w..C.wC.wCCw",
            "CC.C..C..CCC.CC.C...",
            "C.ww...CCC..CC...CCC",
            "...CCC.CwwwC..www.C.",
            "wwCCCCC.w.C.C...wCwC",
            "CCwC.CwCCC.C.w.Cw...",
            "C.w.wC.CC.CCC.C.w.Cw",
            "CCw.CCC..C..CC.CwCCw",
            "C.wwwww.CwwCCwwwwwww"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        CurvyonRails theObject;
        eq(5, theObject.getmin(field),9);
    }
    return 0;
}
// END CUT HERE
