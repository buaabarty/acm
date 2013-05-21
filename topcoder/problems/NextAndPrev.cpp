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
class NextAndPrev {
public:
    int g[26][26];
    int t[26];
    bool rem[26];
    void dfs(int now) {

    }
    int getMinimum(int nextCost, int prevCost, string start, string goal) {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                if (i != j) g[i][j] = 1000000000;
                else g[i][j] = 0;
        for (int i = 0; i < 26; ++i)
            g[i][(i+1)%26] = nextCost,
            g[i][(i+25)%26] = prevCost;
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        memset(t, -1, sizeof(t));
        int n = start.length();
        bool flag = true;
        for (int i = 0; i < n; ++i)
            if (t[start[i]-'a'] < 0) t[start[i]-'a'] = goal[i]-'a';
            else {
                flag = false; break;
            }
        if (!flag) return -1;
        memset(rem, 0, sizeof(rem));
        for (int i = 0; i < n; ++i)
            rem[start[i]-'a'] = 1;
        res = 1000000000;
        dfs(0);
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        NextAndPrev theObject;
        eq(0, theObject.getMinimum(5, 8, "aeaae", "bcbbc"),21);
    }
    {
        NextAndPrev theObject;
        eq(1, theObject.getMinimum(5, 8, "aeaae", "bccbc"),-1);
    }
    {
        NextAndPrev theObject;
        eq(2, theObject.getMinimum(1, 1, "srm", "srm"),0);
    }
    {
        NextAndPrev theObject;
        eq(3, theObject.getMinimum(1000, 39, "a", "b"),975);
    }
    {
        NextAndPrev theObject;
        eq(4, theObject.getMinimum(123, 456, "pqrs", "abab"),-1);
    }
    {
        NextAndPrev theObject;
        eq(5, theObject.getMinimum(100, 19, "topcoder", "ssszsffs"),676);
    }
    {
        NextAndPrev theObject;
        eq(6, theObject.getMinimum(1, 1000, "csk", "wog"),64);
    }
    {
        NextAndPrev theObject;
        eq(7, theObject.getMinimum(7, 6, "qwerty", "jjjjjj"),125);
    }
    {
        NextAndPrev theObject;
        eq(8, theObject.getMinimum(306, 26, "me", "ii"),572);
    }
    return 0;
}
// END CUT HERE
