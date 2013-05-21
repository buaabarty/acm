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
class EqualSums {
public:
    int count(vector <string> board) {
        int res;
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {"1-",
            "-2"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(0, theObject.count(board),4);
    }
    {
        string boardARRAY[] = {"123",
            "4--",
            "--9"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(1, theObject.count(board),1);
    }
    {
        string boardARRAY[] = {"9--",
            "-9-",
            "--9"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(2, theObject.count(board),271);
    }
    {
        string boardARRAY[] = {"11",
            "12"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(3, theObject.count(board),0);
    }
    {
        string boardARRAY[] = {"-4--",
            "-0-2",
            "--1-",
            "4---"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(4, theObject.count(board),10);
    }
    {
        string boardARRAY[] = {"--2",
            "02-",
            "-10"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(5, theObject.count(board),0);
    }
    {
        string boardARRAY[] = {"----------1---------------0-----7-----------------",
            "-----4--------------------------------------------",
            "--------5-------------5-3---5---------------6-----",
            "-------2----------1-------------------------------",
            "-----4--------------------------------------------",
            "-----3--------------------------------------------",
            "-6----------5-------------------------------------",
            "-------------------------------7---5----------6---",
            "--------6-------------6-4---6---------------7-----",
            "-------------4----------------5-------------------",
            "3------------------------------------------6------",
            "3------------------------------------------6------",
            "-------------4----------------5-------------------",
            "---------------2-------------------------3--------",
            "--2------------------------------------------2----",
            "---8---------------1-------------------3----------",
            "---------------3----------------------------------",
            "----7----------------5---0-----------------------5",
            "----------------5-------------------------3-----1-",
            "----------1---------------0-----7-----------------",
            "-------------5----------------6-------------------",
            "-7----------6-------------------------------------",
            "---8---------------1-------------------3----------",
            "-----------------------3--------------------------",
            "----8----------------6---1-----------------------6",
            "------------------------------------------4-----2-",
            "-----------5---------------5----------------------",
            "-----------------------------6--------------------",
            "----8----------------6---1-----------------------6",
            "----------------5-------------------------3-----1-",
            "-------------------------------6---4--2-------5---",
            "-6----------5-------------------------------------",
            "--------5-------------5-3---5---------------6-----",
            "-------------5----------------6-------------------",
            "-----3--------------------------------------------",
            "---------------2-------------------------3--------",
            "---------4---------------------------6------------",
            "-------------------------------6---4--2-------5---",
            "------2-------------1------------22---------------",
            "--------5-------------5-3---5---------------6-----",
            "-----------5--3------------5----------------------",
            "--2------------------------------------------2----",
            "---------5---------------------------7------------",
            "-------------4----------------5-------------------",
            "-----------------5------------------4---6------2--",
            "-------------------------------6---4--2-------5---",
            "-----------------------2--------------------------",
            "----------------6-------------------------4-----2-", 
            "-------------------------------6---4--2-------5---",
            "--------5-------------5-3---5---------------6-----"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        EqualSums theObject;
        eq(6, theObject.count(board),45094393);
    }
    return 0;
}
// END CUT HERE
