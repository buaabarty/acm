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

class TravelOnMars {
public:
    int g[100][100];
    int mindist(int x, int y, int n) {
        if (x < y) swap(x, y);
        return min(x - y, y + n - x);
    }
    int minTimes(vector <int> range, int startCity, int endCity) {
        int n = range.size();
        int inf = 10000000;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) g[i][j] = 0;
                else g[i][j] = inf;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mindist(i, j, n) <= range[i]) g[i][j] = 1;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        return g[startCity][endCity];
    }

};


// Powered by FileEdit
// Powered by CodeProcessor
