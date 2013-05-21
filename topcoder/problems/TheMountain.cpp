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
class TheMountain {
public:
    int minSum(int n, int m, vector <int> rowIndex, vector <int> columnIndex, vector <int> element) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int rowIndexARRAY[] = {0, 0, 0, 1, 1, 1};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {0, 1, 2, 0, 1, 2};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {4, 6, 9, 1, 3, 6};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(0, theObject.minSum(2, 3, rowIndex, columnIndex, element),29);
    }
    {
        int rowIndexARRAY[] = {1, 0, 1};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {2, 2, 0};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {5, 7, 6};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(1, theObject.minSum(2, 3, rowIndex, columnIndex, element),40);
    }
    {
        int rowIndexARRAY[] = {0, 0, 2, 2};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {0, 2, 2, 0};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {1, 1, 1, 1};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(2, theObject.minSum(3, 3, rowIndex, columnIndex, element),15);
    }
    {
        int rowIndexARRAY[] = {0, 0, 1, 1};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {0, 1, 1, 0};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {5, 8, 5, 8};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(3, theObject.minSum(2, 2, rowIndex, columnIndex, element),-1);
    }
    {
        int rowIndexARRAY[] = {0};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {1};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {1};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(4, theObject.minSum(1, 3, rowIndex, columnIndex, element),-1);
    }
    {
        int rowIndexARRAY[] = {2, 3, 5, 7, 11};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {13, 17, 19, 23, 29};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {100, 200, 300, 400, 500};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(5, theObject.minSum(123, 45, rowIndex, columnIndex, element),367047);
    }
    {
        int rowIndexARRAY[] = {5};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {8};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {666};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(6, theObject.minSum(200, 200, rowIndex, columnIndex, element),5737554);
    }
    {
        int rowIndexARRAY[] = {0, 8, 7};
        vector <int> rowIndex( rowIndexARRAY, rowIndexARRAY+ARRSIZE(rowIndexARRAY) );
        int columnIndexARRAY[] = {3, 1, 9};
        vector <int> columnIndex( columnIndexARRAY, columnIndexARRAY+ARRSIZE(columnIndexARRAY) );
        int elementARRAY[] = {5, 4, 7};
        vector <int> element( elementARRAY, elementARRAY+ARRSIZE(elementARRAY) );
        TheMountain theObject;
        eq(7, theObject.minSum(10, 10, rowIndex, columnIndex, element),593);
    }
    return 0;
}
// END CUT HERE
