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
bool cmp(int x, int y) {
    return x > y;
}
// END CUT HERE
class EllysRoomAssignmentsDiv1 {
public:
    int elly, n;
    double tg[1000], tt[1000];
    int eg;
    double getAverage(vector <string> ratings) {
        string tot = "";
        for (int i = 0; i < ratings.size(); ++i)
            tot += ratings[i];
        vector<int> d = splitInt(tot);
        n = d.size();
        elly = d[0];
        sort(d.begin(), d.end(), cmp);
        int r = n / 20;
        if (n%20) ++r;
        memset(tt, 0, sizeof(tt));
        memset(tg, 0, sizeof(tg));
        for (int i = 0; i < n; ++i) {
            tg[i/r] += d[i];
            tt[i/r] += 1.0;
            if (elly == d[i]) eg = i/r;
        }
        int g = n / r;
        if (n%r) ++g;
        for (int i = 0; i < g; ++i) tg[i] /= tt[i];
        double ans = 0;
        if (!(n%r)) {
            ans = elly;
            for (int i = 0; i < g; ++i)
                if (i != eg) ans += tg[i];
            ans /= (double)g;
        } else {
            if (eg != g-1) {
                ans = elly;
                for (int i = 0; i < g; ++i)
                    if (eg != i) {
                        if (i < g-1)  {
                            ans += tg[i];
                        } else {
                            double p1 = tt[i]/(double)r;
                            double p2 = 1-p1;
                            ans = p1*(ans+tg[i])/(double)g + p2*ans/(double)(g-1);
                        }
                    }

            } else {
                ans = elly;
                for (int i = 0; i < g; ++i)
                    if (eg != i) ans += tg[i];
                ans /= (double)(g);
            }
        }
        return ans;
    }

};
