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
class TheExperiment {
public:
    int f[301][301][2];
    int s[301][301];
    int dat[301];
    string tot;
    int countPlacements(vector <string> intensity, int M, int L, int A, int B) {
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        f[0][0][1] = 1;
        f[0][0][0] = 1;
        s[0][0] = 1;
        tot = "";
        for (int i = 0; i < intensity.size(); ++i) tot = tot + intensity[i];
        int n = tot.length();
        for (int i = 1; i <= n; ++i) dat[i] = tot[i-1] - '0';
        for (int i = 1; i <= n; ++i)
            printf("%d%c", dat[i], " \n"[i==n]);
        for (int i = 1; i <= n; ++i)
            s[i][0] = 1;
        for (int i = 1; i <= M; ++i)
            s[0][i] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= M; ++j) {
                int now = 0;
                for (int k = 1; k <= L; ++k) {
                    if (i - k < 0) break;
                    now = now + dat[i - k + 1];
                    if (now >= A && now <= B) {
                        if (k == L) {
                            f[i][j][1] += s[i-k][j-1] + f[i-k][j-1][0];
                        } else {
                            f[i][j][0] += f[i-k][j-1][0];
                            f[i][j][1] += f[i-k][j-1][1];
                        }
                    }
                }
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + f[i][j][1];
            }
        int res = 0;
        cout << f[4][4][0] << " " << f[4][4][1] << endl;
        for (int i = 1; i <= n; ++i)
            res += f[i][M][1];
        return res;
    }

};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string intensityARRAY[] = {"341156"};
        vector <string> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
        TheExperiment theObject;
        eq(0, theObject.countPlacements(intensity, 3, 3, 6, 10),2);
    }
    {
        string intensityARRAY[] = {"999112999"};
        vector <string> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
        TheExperiment theObject;
        eq(1, theObject.countPlacements(intensity, 2, 4, 21, 30),2);
    }
    {
        string intensityARRAY[] = {"111"};
        vector <string> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
        TheExperiment theObject;
        eq(2, theObject.countPlacements(intensity, 2, 2, 2, 3),0);
    }
    {
        string intensityARRAY[] = {"59059", "110", "1132230231"};
        vector <string> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
        TheExperiment theObject;
        eq(3, theObject.countPlacements(intensity, 1, 5, 10, 20),6);
    }
    {
        string intensityARRAY[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"};
        vector <string> intensity( intensityARRAY, intensityARRAY+ARRSIZE(intensityARRAY) );
        TheExperiment theObject;
        eq(4, theObject.countPlacements(intensity, 12, 8, 4, 2700),418629948);
    }
    return 0;
}
// END CUT HERE
