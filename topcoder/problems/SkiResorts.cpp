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
typedef long long LL;
const LL maxn = 1000;
LL tsize, table[maxn*2];
const LL inf = 100000000000000000LL;
void init_table() {
    sort(table, table+tsize);
    tsize = unique(table, table+tsize)-table;
}

LL get_index(LL key) {
    return lower_bound(table, table+tsize, key)-table;
}
struct data {
    LL x, y;
    data(LL _x, LL _y) {
        x = _x, y = _y;
    }
    data() {}
};
LL a[maxn], n;
LL d[maxn][maxn];
bool inq[maxn][maxn];
bool g[maxn][maxn];
queue<data> q;
class SkiResorts {
public:
    LL iabs(LL x) {
        return (x < 0) ? -x : x;
    }
    void spfa(LL v, LL x) {
        while (!q.empty()) q.pop();
        for (LL i = 0; i < n; ++i)
            for (LL j = 0; j < n; ++j)
                d[i][j] = inf;
        memset(inq, 0, sizeof(inq));
        for (LL i = 0; i < tsize; ++i) {
            d[v][i] = iabs(table[i] - table[x]);
            inq[v][i] = 1;
            q.push(data(v, i));
        }
        while (!q.empty()) {
            data now = q.front(); q.pop();
            //cout << now.x << " " << now.y << " " << d[now.x][now.y] << endl;
            for (LL i = 0; i < n; ++i) if (g[now.x][i])
                for (LL j = 0; j < tsize; ++j) {
                    LL cost = d[now.x][now.y];
                    if (now.y < j) break;
                    cost += iabs(table[j]-table[a[i]]);
                    if (cost < d[i][j]) {
                        d[i][j] = cost;
                        if (!inq[i][j]) {
                            inq[i][j] = 1;
                            q.push(data(i, j));
                        }
                    }
                }
            inq[now.x][now.y] = 0;
        }
    }
    long long minCost(vector <string> road, vector <int> altitude) {
        tsize = 0;
        n = altitude.size();
        for (LL i = 0; i < n; ++i)
            table[tsize++] = altitude[i];
        init_table();
        for (LL i = 0; i < n; ++i)
            a[i] = get_index(altitude[i]);
        for (LL i = 0; i < n; ++i)
            for (LL j = 0; j < n; ++j)
                g[i][j] = (road[i][j] == 'Y');
        spfa(0, a[0]);
        LL res = inf;
        for (LL i = 0; i < tsize; ++i)
            res = min(res, d[n-1][i]);
        if (res == inf) res = -1;
        return res;
    }
};
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string roadARRAY[] = {"NYN",
            "YNY",
            "NYN"};
        vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        int altitudeARRAY[] = {30, 20, 10};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResorts theObject;
        eq(0, theObject.minCost(road, altitude),0LL);
    }
    {
        string roadARRAY[] = {"NY",
            "YN"};
        vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        int altitudeARRAY[] = {10, 20};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResorts theObject;
        eq(1, theObject.minCost(road, altitude),10LL);
    }
    {
        string roadARRAY[] = {"NYN",
            "YNN",
            "NNN"};
        vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        int altitudeARRAY[] = {573, 573, 573};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResorts theObject;
        eq(2, theObject.minCost(road, altitude),-1LL);
    }
    {
        string roadARRAY[] = {"NNYNNYYYNN",
            "NNNNYNYNNN",
            "YNNNNYYNNN",
            "NNNNNNYNYY",
            "NYNNNNNNYY",
            "YNYNNNNYNN",
            "YYYYNNNYNN",
            "YNNNNYYNNN",
            "NNNYYNNNNN",
            "NNNYYNNNNN"};
        vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
        int altitudeARRAY[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResorts theObject;
        eq(3, theObject.minCost(road, altitude),12LL);
    }
    return 0;
}
// END CUT HERE
