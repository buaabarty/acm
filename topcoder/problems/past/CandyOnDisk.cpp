/* &*#()&*#)&E*F& */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define REP(I, N) for (int I=0;I<int(N);++I)
#define FOR(I, A, B) for (int I=int(A);I<int(B);++I)
#define DWN(I, B, A) for (int I=int(B-1);I>=int(A);--I)
#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)

#define ALL(A) A.begin(), A.end()
#define CLR(A) A.clear()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define SRT(A) sort(ALL(A))
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef double DB;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}

template<class T> inline void checkMin(T &a, T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a, T b){if (b>a) a=b;}

/* -&$&#*( &#*@)^$@&*)*/

const int MOD = 1000000007;
const int INF = 0x7fffffff;

const int N = 50;
namespace Geo{
	#define typec double
    const typec eps=1e-9;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct Point2D{
		typec x,y;
		Point2D(){}
		Point2D(typec _x,typec _y):x(_x),y(_y){};
		void input(){
			scanf("%lf%lf",&x,&y);
		}
		void output(){
			printf("%.2f %.2f\n",x,y);
		}
		bool operator==(Point2D a)const{
			return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
		}
		bool operator<(Point2D a)const{
			return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
		}
		typec len(){
			return hypot(x,y);
		}
		typec len2(){
			return x*x+y*y;
		}
		Point2D operator + (const Point2D &A) const{
			return Point2D(x + A.x , y + A.y);
		}
		Point2D operator - (const Point2D &A) const{
			return Point2D(x - A.x , y - A.y);
		}
		Point2D operator * (const typec _x) const{
			return Point2D(x * _x , y * _x);
		}
		typec operator * (const Point2D &A) const{
			return x * A.x + y * A.y;
		}
		typec operator ^ (const Point2D &A) const{
			return x * A.y - y * A.x;
		}
		Point2D operator / (const typec _p) const{
			return Point2D(x / _p , y / _p);
		}
		typec distance(Point2D p){
			return sqrt(sqr(x-p.x) + sqr(y-p.y));
		}
		Point2D add(Point2D p){
			return Point2D(x+p.x,y+p.y);
		}
		Point2D sub(Point2D p){
			return Point2D(x-p.x,y-p.y);
		}
		Point2D mul(typec b){
			return Point2D(x*b,y*b);
		}
		Point2D div(typec b){
			return Point2D(x/b,y/b);
		}
		typec dot(Point2D p){
			return x*p.x+y*p.y;
		}
		typec det(Point2D p){
			return x*p.y-y*p.x;
		}
		typec rad(Point2D a,Point2D b){
			Point2D p=*this;
			return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
		}
		Point2D trunc(typec r){
			typec l=len();
			if (!dblcmp(l))return *this;
			r/=l;
			return Point2D(x*r,y*r);
		}
		Point2D rotleft(){
			return Point2D(-y,x);
		}
		Point2D rotright(){
			return Point2D(y,-x);
		}
		Point2D rotate(Point2D p,typec angle)//ÈÆµãpÄæÊ±ÕëÐý×ªangle½Ç¶È
		{
			Point2D v=this->sub(p);
			typec c=cos(angle),s=sin(angle);
			return Point2D(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
		}
	};

	typec cross(Point2D a,Point2D b,Point2D c){
		return (b.sub(a)).det(c.sub(a));
	}
}using namespace Geo;
struct Circle{
    Point2D O;
    double r;
}c[1000];
Point2D s , t;
double vis[1000];
class CandyOnDisk {
public:
    int n;
    void dfs(int x){
//        printf("Loc %d:\n" , x);
//        bool ret = false;
        REP(i , n){
            if (i == x || dblcmp(vis[i]) == 0) continue;
            double rt = c[x].O.distance(c[i].O);
            double ret = -1;
            if (dblcmp(vis[x] - rt) >= 0 && dblcmp(vis[x] - rt - c[i].r) <= 0) ret = vis[x] + rt  - c[i].r;
            else ret = vis[x] + c[i].r - rt;
//            cout << rt << endl;
            if (dblcmp(ret) >= 0){
//                printf("Cango %d\n" , i);
                if (dblcmp(vis[i]) < 0 || dblcmp(vis[i] - ret) > 0){
//                    ret = true;
                    vis[i] = ret;
                    dfs(i);
                }
            }
            ret = -1;
            if (dblcmp(c[x].r - rt) >= 0 && dblcmp(c[x].r - rt - c[i].r) <= 0) ret = vis[x] + rt  - c[i].r;
            else ret = c[x].r + c[i].r - rt;
//            cout << rt << endl;
            if (dblcmp(ret) >= 0){
//                printf("Cango %d\n" , i);
                if (dblcmp(vis[i]) < 0 || dblcmp(vis[i] - ret) > 0){
//                    ret = true;
                    vis[i] = ret;
                    dfs(i);
                }
            }
        }
//        return ret;
    }
	string ableToAchieve(vector <int> x, vector <int> y, vector <int> r, int sx, int sy, int tx, int ty) {
		n = SZ(x);
		REP(i , n){
		    c[i].O.x = x[i];
		    c[i].O.y = y[i];
		    c[i].r = r[i];
		}
		s.x = sx;
        s.y = sy;
        t.x = tx;
        t.y = ty;
		if (s == t) return "YES";
		bool one = true;

		REP(i , n){
		    double rt = c[i].O.distance(s);
		    if (dblcmp(c[i].r - rt) >= 0){
                REP(j , n){
                    if (i == j) continue;
                    if (dblcmp(c[i].O.distance(c[j].O) - rt - c[j].r) <= 0) one = false;
                }
		    }
		}
		if (one){
            double rt1 = c[0].O.distance(s) , rt2 = c[0].O.distance(t);
            if (dblcmp(c[0].r - rt1) >= 0 && dblcmp(c[0].r - rt2) >= 0 && dblcmp(rt1 - rt2) == 0) return "YES";
            return "NO";
		}
        REP(i , n) vis[i] = -1;
        REP(i , n){
            double rt = c[i].O.distance(s);
//            printf("%.2lf\n" , vis[i]);
            if (dblcmp(c[i].r - rt) >= 0 && (dblcmp(vis[i]) < 0 || dblcmp(vis[i] - rt) > 0)){
                vis[i] = rt;
                dfs(i);
            }
        }
        REP(i , n){
            double rt = c[i].O.distance(t);
            if (dblcmp(rt - c[i].r) > 0) continue;
            if (dblcmp(vis[i]) >= 0 && dblcmp(vis[i] - rt) <= 0) return "YES";
        }
        return "NO";
	}
};


// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int x[]                   = {0, 4};
			int y[]                   = {0, 0};
			int r[]                   = {3, 3};
			int sx                    = -1;
			int sy                    = -2;
			int tx                    = 6;
			int ty                    = 1;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 3};
			int y[]                   = {0, 0};
			int r[]                   = {5, 3};
			int sx                    = -4;
			int sy                    = 0;
			int tx                    = -2;
			int ty                    = 0;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0};
			int y[]                   = {0};
			int r[]                   = {1};
			int sx                    = 0;
			int sy                    = 0;
			int tx                    = 571;
			int ty                    = 571;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0};
			int y[]                   = {0};
			int r[]                   = {1};
			int sx                    = 571;
			int sy                    = 571;
			int tx                    = 571;
			int ty                    = 571;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
			int y[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
			int r[]                   = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
			int sx                    = 2;
			int sy                    = 2;
			int tx                    = 19;
			int ty                    = 19;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
			int y[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
			int r[]                   = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int sx                    = 2;
			int sy                    = 2;
			int tx                    = 19;
			int ty                    = 19;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

        case 6: {
			int x[]                   = {69, 70, 78, 79, 88, 89, 92, 98, 98, 107, 108, 113, 118, 120, 125, 125, 133, 139, 142, 147, 157, 160, 167, 177, 185, 192, 193, 195, 202, 205, 211, 220, 225, 230, 236, 243, 243, 252, 256, 266, 268, 276, 284, 285, 289, 294, 297, 299, 299, 307};
			int y[]                   = {-76, -69, -60, -53, -47, -40, -30, -27, -21, -20, -19, -15, -11, -8, -1, 5, 12, 13, 14, 24, 28, 31, 34, 41, 46, 48, 56, 66, 76, 84, 89, 92, 98, 103, 103, 108, 110, 117, 117, 126, 129, 136, 146, 149, 159, 164, 164, 173, 174, 174};
			int r[]                   = {10, 10, 14, 4, 17, 15, 3, 18, 2, 16, 18, 5, 8, 13, 20, 4, 20, 12, 15, 9, 7, 16, 5, 14, 9, 19, 6, 7, 14, 10, 14, 5, 16, 13, 6, 20, 4, 7, 7, 6, 11, 9, 18, 12, 12, 19, 15, 17, 4, 10};
			int sx                    = 65;
			int sy                    = -75;
			int tx                    = 286;
			int ty                    = 149;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			int sx                    = ;
			int sy                    = ;
			int tx                    = ;
			int ty                    = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			int sx                    = ;
			int sy                    = ;
			int tx                    = ;
			int ty                    = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CandyOnDisk().ableToAchieve(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), sx, sy, tx, ty);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
