/*
 * =====================================================================================
 *
 *         Author:  KissBuaa.DS(AC)
 *        Company:  BUAA-ACMICPC-Group
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#include <math.h>
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define abs(x) ((x)<0?(-(x)):(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
#define loabit(x) ((x)&(-(x)))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
//For C++
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <iostream>
#define inf 100000000000000LL
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int n,m,T;
const int N = 2000;
int a[N][N];
LL sum[N];
LL sumall;

void solve(int r, LL sum[], LL &mintot, int &mini){
    LL tot = 0;
    for (int i = 0; i < r; ++i)
        tot += sum[i] * (2 + i * 4);
    mintot = inf;
    mini = -1;
    for (int i = 0; i <= r; ++i){
        LL now = 0;
        for (int k = 0; k <= r; ++k)
            now += sum[k] * sqr((2 + k * 4) - i * 4);
        if (now < mintot){
            mintot = now;
            mini = i;
        }
    }
}

int main(){
    int r, c;
    while (cin >> r >> c){
        sumall = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j){
                scanf("%d", &a[i][j]);
                sumall += a[i][j];
            }
        LL toti, totj; int indi, indj;
        for (int i = 0; i < r; ++i){
            sum[i] = 0;
            for (int j = 0; j < c; ++j)
                sum[i] += a[i][j];
        }
        solve(r, sum, toti, indi);
        for (int j = 0; j < c; ++j){
            sum[j] = 0;
            for (int i = 0; i < r; ++i)
                sum[j] += a[i][j];
        }
        solve(c, sum, totj, indj);
        cout << toti + totj << endl;
        cout << indi << " " << indj << endl;
    }
}
