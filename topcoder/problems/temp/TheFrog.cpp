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
#define eps 1e-15
double s[30000*100+100];
class TheFrog {
public:
    bool small(double x, double y) {
        return x < y - eps;
    }
    double getMinimum(int D, vector <int> L, vector <int> R) {
        vector<int> d;
        int n = L.size(), mx = 0;
        for (int i = 0; i < n; ++i) if (L[i]) d.push_back(L[i]);
        for (int i = 0; i < n; ++i)
            mx = max(mx, R[i] - L[i]);
        for (int i = 0; i < n; ++i) if (R[i]) d.push_back(R[i]);

        int cnt = 0;
        for (int i = 0; i < d.size(); ++i)
            for (int j = 1; j <= D; ++j) {
                if (d[i] < j * mx) break;
                double x = d[i] / (double)j;
                s[cnt++] = x;
            }
        sort(s, s+cnt);
        for (int i = 0; i < cnt; ++i) {
            //cout << s[i] << endl;
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                int k = (int)(floor(L[j] / s[i]+eps)+eps);
                if (!small(L[j]*1.0, k*s[i])) ++k;
                //cout << j << " " << k << endl;
                if (small(k*s[i], R[j]*1.0)) {
                    flag = false;
                    break;
                }
            }
            if (flag) return s[i];
        }
        return 0;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int LARRAY[] = {2};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {7};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(0, theObject.getMinimum(16, L, R),7.0);
    }
    {
        int LARRAY[] = {11, 3};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {21, 7};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(1, theObject.getMinimum(25, L, R),10.5);
    }
    {
        int LARRAY[] = {0};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {100};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(2, theObject.getMinimum(100, L, R),100.0);
    }
    {
        int LARRAY[] = {29950, 29951, 29952, 29953, 29954, 29955, 29956, 29957, 29958, 29959, 29960, 29961, 29962, 29963, 29964, 29965, 29966, 29967, 29968, 29969, 29970, 29971, 29972, 29973, 29974, 29975, 29976, 29977, 29978, 29979, 29980, 29981, 29982, 29983, 29984, 29985, 29986, 29987, 29988, 29989, 29990, 29991, 29992, 29993, 29994, 29995, 29996, 29997, 29998, 29999};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {29951, 29952, 29953, 29954, 29955, 29956, 29957, 29958, 29959, 29960, 29961, 29962, 29963, 29964, 29965, 29966, 29967, 29968, 29969, 29970, 29971, 29972, 29973, 29974, 29975, 29976, 29977, 29978, 29979, 29980, 29981, 29982, 29983, 29984, 29985, 29986, 29987, 29988, 29989, 29990, 29991, 29992, 29993, 29994, 29995, 29996, 29997, 29998, 29999, 30000};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(3, theObject.getMinimum(30000, L, R),1.0);
    }
    {
        int LARRAY[] = {17, 25281, 5775, 2825, 14040};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {55, 26000, 5791, 3150, 14092};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(4, theObject.getMinimum(30000, L, R),787.8787878787879);
    }
    return 0;
}
// END CUT HERE
