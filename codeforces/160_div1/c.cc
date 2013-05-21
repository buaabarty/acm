#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100][100];
int gao(int mm, int x) {
    if (mm == 2) {
        if (x == 1) return 1;
        else return 0;
    }
}
int main() {
    /*int n; scanf("%d", &n);
    int ss = 1;
    while (ss < n) ss = ss * 2;
    gao(ss, n)*/
    int m = 70;
    for (int j = 1; j <= m; ++j)
        a[1][j] = 0;
    a[1][m+1] = 1;
    for (int i = 2; i <= m + 1; ++i)
        for (int j= 1; j <= m + 1; ++j)
            if (j == 1) a[i][j] = a[i-1][j+1];
            else {
                if (j == m + 1) a[i][j] = a[i-1][j-1];
                else a[i][j] = a[i-1][j-1]^a[i-1][j+1];
            }
    for (int i = 0; i <= m+1; ++i) {
        int s = 0;
        for (int j = 1; j <= m+1; ++j)
            s += a[i][j];
        printf("%d:%d\n", i, s);
    }
    return 0;
}
