// =====================================================================================
// 
//       Filename:  c.cc
// 
//    Description:  crack
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

int g1[21][21], g2[21][21], n;
bool use[21];

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

void dijkstra(int st, int d[], int g[][21]) {
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

int x[21], y[21], s[21], t[21], m, p, d[21];
int d1[21], d2[21];

bool okay(int mask, int loc) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j) g1[i][j] = 0, g2[i][j] = 0;
            else g1[i][j] = inf, g2[i][j] = inf;

    for (int i = 0; i < m; ++i)
        if ((1<<i)&mask) {
            checkMin(g1[x[i]][y[i]], s[i]);
            checkMin(g2[y[i]][x[i]], s[i]);
        } else {
            checkMin(g1[x[i]][y[i]], t[i]);
            checkMin(g2[y[i]][x[i]], t[i]);
        }
    dijkstra(1, d1, g1);
    dijkstra(2, d2, g2);
//    printf("%d %d %d %d\n", d1[x[loc]], d2[y[loc]], s[loc], d1[2]);
    return (d1[x[loc]] < inf) && (d2[y[loc]] < inf) && (d1[x[loc]] + d2[y[loc]] + s[loc] == d1[2]);
}

int main (int argc, char *argv[]) {
    freopen("C-small-attempt0.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &p);
        static int ri = 0;
        printf("Case #%d: ", ++ri);
        for (int i = 0; i < m; ++i) scanf("%d%d%d%d", &x[i], &y[i], &s[i], &t[i]);
        for (int i = 0; i < p; ++i) scanf("%d", d+i), --d[i];
        int st = 0, mask = (1<<m);
        bool find = false;
        for (int i = 0; i < p; ++i) {
            st = (1<<d[i]);
            int flag = 0;
            for (int j = 0; j < mask; ++j) 
                if ((st&j) == st) {
                    if (okay(j, d[i])) {
                        flag = j + 1;
                        break;
                    }
                }
            if (!flag) {
                printf("%d", d[i] + 1);
                find = true;
                break;
            }
            char str[100];
            itoa(flag - 1, str, 2);
            printf("mask = %s\t", str);
            itoa(st, str, 2);
            printf("st = %s\n", str);
        }
        if (!find) printf("Looks Good To Me\n");
    }
    return 0;
}
