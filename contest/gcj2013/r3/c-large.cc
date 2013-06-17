// =====================================================================================
// 
//       Filename:  c-large.cc
// 
//    Description:  dijkstra
// 
//        Version:  1.0
//        Created:  2013年06月15日 22时23分32秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Boyang Yang (barty), maiL@barty.ws
//        Company:  http://barty.ws
// 
// =====================================================================================


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
#include <cmath>
#include <cstring>
using namespace std;
template <typename T> void checkMin(T &a, const T &b) { if (b < a) a = b; }
template <typename T> void checkMax(T &a, const T &b) { if (b > a) a = b; }

const int inf = 1000000000;
const int maxn = 1000 + 9;

int g1[maxn][maxn], g2[maxn][maxn], n, g11[maxn][maxn], g22[maxn][maxn];
bool use[maxn];


void   itoa   (   unsigned   long   val,   char   *buf,   unsigned   radix    )   
{   
                char   *p;                                 /*   pointer   to   traverse   string   */   
                char   *firstdig;                   /*   pointer   to   first   digit   */   
                char   temp;                             /*   temp   char   */   
                unsigned   digval;                 /*   value   of   digit   */   

                p   =   buf;   
                firstdig   =   p;                       /*   save   pointer   to   first   digit   */   

                do   {   
                                        digval   =   (unsigned)   (val   %   radix);   
                                        val   /=   radix;               /*   get   next   digit   */   
                
                                        /*   convert   to   ascii   and   store   */   
                                        if   (digval   >   9)   
                                                *p++   =   (char   )   (digval   -   10   +   'a');     /*   a   letter   */   
                                        else   
                                                *p++   =   (char   )   (digval   +   '0');               /*   a   digit   */   
                                }   while   (val   >   0);   

                /*   We   now   have   the   digit   of   the   number   in   the   buffer,   but   in   reverse   
                 *                         order.     Thus   we   reverse   them   now.   */   

                *p--   =   '\0';                         /*   terminate   string;   p   points   to   last   digit   */   

                do   {   
                                        temp   =   *p;   
                                        *p   =   *firstdig;   
                                        *firstdig   =   temp;       /*   swap   *p   and   *firstdig   */   
                                        --p;   
                                        ++firstdig;                   /*   advance   to   next   two   digits   */   
                                }   while   (firstdig   <   p);   /*   repeat   until   halfway   */   
}

void dijkstra(int st, int d[], int g[][maxn]) {
    for (int i = 1; i <= n; ++i) d[i] = inf;
    d[st] = 0;
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= n; ++i) {
        int mx = -1, mt = inf;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && d[j] < mt) {
                mt = d[j];
                mx = j;
            }
        if (mx == -1) return ;
        use[mx] = 1;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && g[mx][j] + mt < d[j]) {
                d[j] = g[mx][j] + mt;
            }
    }
}

int x[maxn], y[maxn], s[maxn], t[maxn], m, p, d[maxn];
int d1[maxn], d2[maxn], d11[maxn], d22[maxn];

bool okay(int loc) {
    cout << loc << endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j) g1[i][j] = 0, g2[i][j] = 0, g11[i][j] = 0, g22[i][j] = 0;
            else g1[i][j] = inf, g2[i][j] = inf, g11[i][j] = inf, g22[i][j] = inf;

    for (int i = 0; i < m; ++i) {
            checkMin(g1[x[i]][y[i]], s[i]);
            checkMin(g2[y[i]][x[i]], s[i]);
            checkMin(g11[x[i]][y[i]], t[i]);
            checkMin(g22[y[i]][x[i]], t[i]);
    }
    dijkstra(1, d1, g1);
    dijkstra(2, d2, g2);
    dijkstra(1, d11, g11);
    dijkstra(2, d22, g22);
    //for (int i = 1; i <= n; ++i)
    //    printf("%d%c", d11[i], " \n"[i==n]);
    if (d1[x[loc]] >= inf || d2[y[loc]] >= inf) return false;
    //cout << "GOT1" << endl;
    printf("%d %d %d %d\n", d1[x[loc]], s[loc], d2[y[loc]], d11[2]);
    if (d1[x[loc]] + s[loc]  + d2[y[loc]] > d11[2]) return false;
    printf("%d %d %d\n", d1[x[loc]], s[loc], d11[y[loc]]);
    //cout << "GOT2" << endl;
    if (d1[x[loc]] + s[loc] > d11[y[loc]]) return false;
    printf("%d %d %d\n", d2[y[loc]], s[loc], d22[x[loc]]);
    //cout << "GOT3" << endl;
    if (d2[y[loc]] + s[loc] > d22[x[loc]]) return false;
    //cout << "GOT4" << endl;
    return true;
}

int main (int argc, char *argv[]) {
    freopen("check.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &p);
        static int ri = 0;
        printf("Case #%d: ", ++ri);
        for (int i = 0; i < m; ++i) scanf("%d%d%d%d", &x[i], &y[i], &s[i], &t[i]);
        for (int i = 0; i < p; ++i) scanf("%d", d+i), --d[i];
        bool find = false;
        for (int i = 0; i < p; ++i) {
            int temp = t[d[i]];
            t[d[i]] = inf;
            if (!okay(d[i])) {
                printf("%d\n", d[i] + 1);
                find = true;
                break;
            }
            t[d[i]] = temp;
        }
        if (!find) printf("Looks Good To Me\n");
    }
    return 0;
}
